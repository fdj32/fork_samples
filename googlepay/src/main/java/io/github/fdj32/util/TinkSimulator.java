package io.github.fdj32.util;

import java.io.ByteArrayOutputStream;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.security.GeneralSecurityException;
import java.security.interfaces.ECPrivateKey;
import java.security.interfaces.ECPublicKey;
import java.util.Arrays;
import java.util.Base64;
import java.util.List;

import org.apache.commons.io.IOUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.google.crypto.tink.subtle.Hex;

import io.github.fdj32.model.EnvironmentKey;
import io.github.fdj32.model.Token;

public class TinkSimulator {
	
	private static final Logger LOG = LoggerFactory.getLogger(TinkSimulator.class);
	
	/** PaymentMethodTokenConstants */
	public static final String GOOGLE_SENDER_ID = "Google";
	public static final String HMAC_SHA256_ALGO = "HmacSha256";
	public static final byte[] HKDF_EMPTY_SALT = new byte[0];
	public static final byte[] GOOGLE_CONTEXT_INFO_ECV1 = "Google".getBytes(StandardCharsets.UTF_8);
	public static final String AES_CTR_ALGO = "AES/CTR/NoPadding";
	// Zero IV is fine here because each encryption uses a unique key.
	public static final byte[] AES_CTR_ZERO_IV = new byte[16];
//	public static final EllipticCurves.CurveType P256_CURVE_TYPE = EllipticCurves.CurveType.NIST_P256;
//	public static final EllipticCurves.PointFormatType UNCOMPRESSED_POINT_FORMAT = EllipticCurves.PointFormatType.UNCOMPRESSED;
	public static final String PROTOCOL_VERSION_EC_V1 = "ECv1";
	public static final String PROTOCOL_VERSION_EC_V2 = "ECv2";
	public static final String PROTOCOL_VERSION_EC_V2_SIGNING_ONLY = "ECv2SigningOnly";
//	public static final HashType ECDSA_HASH_SHA256 = HashType.SHA256;

	public static final String JSON_ENCRYPTED_MESSAGE_KEY = "encryptedMessage";
	public static final String JSON_EPHEMERAL_PUBLIC_KEY = "ephemeralPublicKey";
	public static final String JSON_INTERMEDIATE_SIGNING_KEY = "intermediateSigningKey";
	public static final String JSON_KEY_EXPIRATION_KEY = "keyExpiration";
	public static final String JSON_KEY_VALUE_KEY = "keyValue";
	public static final String JSON_MESSAGE_EXPIRATION_KEY = "messageExpiration";
	public static final String JSON_PROTOCOL_VERSION_KEY = "protocolVersion";
	public static final String JSON_SIGNATURES_KEY = "signatures";
	public static final String JSON_SIGNATURE_KEY = "signature";
	public static final String JSON_SIGNED_KEY_KEY = "signedKey";
	public static final String JSON_SIGNED_MESSAGE_KEY = "signedMessage";
	public static final String JSON_TAG_KEY = "tag";
	/** PaymentMethodTokenConstants */

	private static final String SENDER_ID = "Google";
	private static final String RECIPIENT_PREFIX = "merchant:";
	private static final String ECv2 = "ECv2";

//	private static final String PUBLIC_KEY = "BIOCqGybpJXPE6O6T82kIhpiNWBAgLPqceuBiXkfcnqGXIWb3tpAPxM5OXZfjUq2TU1WM0Rt1vMNqEYwx3DQBCk=";
//	private static final String PRIVATE_KEY = "MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgy7oHLlY7fl8GGcHHTr5Wfp4bpBW5Ywlpq3pCc/+gEcmhRANCAASDgqhsm6SVzxOjuk/NpCIaYjVgQICz6nHrgYl5H3J6hlyFm97aQD8TOTl2X41Ktk1NVjNEbdbzDahGMMdw0AQp";
//	private static final String MERCHANT_ID = "12345678901234567890";
//	private static final String MERCHANT_NAME = "Active Network";
//	private static final String RECIPIENT_ID = RECIPIENT_PREFIX + MERCHANT_ID;

	
	/** URL to fetch keys for environment production. */
	public static final String KEYS_URL_PRODUCTION = "https://payments.developers.google.com/paymentmethodtoken/keys.json";
	/** URL to fetch keys for environment test. */
	public static final String KEYS_URL_TEST = "https://payments.developers.google.com/paymentmethodtoken/test/keys.json";
	
	private static EnvironmentKey environmentKey;
	private static ECPublicKey environmentECPublicKey;
	
	private static String getTrustedSigningKeysJson() throws Exception {
		return IOUtils.toString(new URL(KEYS_URL_TEST), StandardCharsets.UTF_8);
	}
	
	private static ECPublicKey getEnvironmentECPublicKey() throws Exception {
		if (null != environmentKey && null != environmentECPublicKey && !environmentKey.expired()) {
			return environmentECPublicKey;
		}
		
		String keysJson = getTrustedSigningKeysJson();
		List<EnvironmentKey> ekList = EnvironmentKey.parse(keysJson);
		EnvironmentKey ecv2EnvKey = ekList.stream().filter(ek -> ECv2.equals(ek.getProtocolVersion())).findFirst().get();
		environmentKey = ecv2EnvKey;
		environmentECPublicKey = EC.str2ECPubKey(ecv2EnvKey.getKeyValue());
		return environmentECPublicKey;
	}
	
	private static byte[] getSignedBytes(String merchantId, String signedMessage) throws Exception {
		return toLengthValue(
				// The order of the parameters matters.
				SENDER_ID, RECIPIENT_PREFIX + merchantId, ECv2, signedMessage);
	}

	private static byte[] intToByteArray(int capacity, int value) {
		final byte[] result = new byte[capacity];
		for (int i = 0; i < capacity; i++) {
			result[i] = (byte) ((value >> (8 * i)) & 0xFF);
		}
		return result;
	}

	private static byte[] toLengthValue(String... chunks) throws Exception {
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		for (String chunk : chunks) {
			byte[] bytes = chunk.getBytes(StandardCharsets.UTF_8);
			baos.write(intToByteArray(4, bytes.length));
			baos.write(bytes);
		}
		return baos.toByteArray();
	}
	
	public static String unseal(String merchantId, String merchantPrivateKeyStr, String sealedMessage) throws Exception {
		// 1. Get current environment trusted signing ECPublicKey
		ECPublicKey envTrustedSigningECPublicKey = getEnvironmentECPublicKey();
		// 2. Parse sealedMessage
		Token t = Token.parse(sealedMessage);
		// 3. Verify IntermediateSigningKey
		if (t.getIntermediateSigningKey().getSignedKey().expired()) {
			LOG.error("token.intermediateSigningKey.signedKey expired.");
			return null;
		}
		byte[] signature = Base64.getDecoder().decode(t.getIntermediateSigningKey().getSignatures().get(0));
		byte[] signedBytes = toLengthValue(
				// The order of the parameters matters.
				SENDER_ID, ECv2, t.getIntermediateSigningKey().getSignedKeyText());
		ECPublicKey intermediateSigningKey = EC.str2ECPubKey(t.getIntermediateSigningKey().getSignedKey().getKeyValue());
		boolean verifyIntermediateSigningKey = EC.verify(signedBytes, signature, envTrustedSigningECPublicKey);
		if (!verifyIntermediateSigningKey) {
			LOG.error("token.intermediateSigningKey.signedKey not verified.");
			return null;
		}
		// 4. Verify signedMessage
		signature = Base64.getDecoder().decode(t.getSignature());
		String signedMessage = t.getSignedMessageText();
		signedBytes = getSignedBytes(merchantId, signedMessage);
		boolean verifySignedMessage = EC.verify(signedBytes, signature, intermediateSigningKey);
		if (!verifySignedMessage) {
			LOG.error("token.signedMessage not verified.");
			return null;
		}
		// 5. Generate merchant ECPrivateKey
		ECPrivateKey myPrivateKey = EC.str2ECPriKey(merchantPrivateKeyStr);
		// 6. Generate ephemeralPublicKey with token.signedMessage.ephemeralPublicKey and merchant private key Base64 string
		ECPublicKey ephemeralPublicKey = EC.generatePublic(t.getSignedMessage().getEphemeralPublicKey(), merchantPrivateKeyStr);
		// 7. computeSharedSecret
		byte[] sharedSecret = EC.computeSharedSecret(ephemeralPublicKey, myPrivateKey);
		// demKeySize = aesCtrKeySize + hmacSha256KeySize
		int demKeySize = 256 / 8 + 256 / 8;
		// 8. computeEciesHkdfSymmetricKey
		byte[] demKey = Hkdf.computeEciesHkdfSymmetricKey(
				Base64.getDecoder().decode(t.getSignedMessage().getEphemeralPublicKey()), sharedSecret,
				HMAC_SHA256_ALGO, HKDF_EMPTY_SALT, GOOGLE_CONTEXT_INFO_ECV1, demKeySize);
		byte[] bcDemKey = BCHKDF.computeEciesHkdfSymmetricKey(
				Base64.getDecoder().decode(t.getSignedMessage().getEphemeralPublicKey()), sharedSecret, HKDF_EMPTY_SALT,
				GOOGLE_CONTEXT_INFO_ECV1, demKeySize);
		LOG.info("Hkdf.computeEciesHkdfSymmetricKey   = {}", Hex.encode(demKey));
		LOG.info("BCHKDF.computeEciesHkdfSymmetricKey = {}", Hex.encode(bcDemKey));
		// 9. derive hmacSha256Key from demKey, the second half of demKey
		byte[] hmacSha256Key = Arrays.copyOfRange(demKey, 256 / 8, demKey.length);
		// 10. decode token.signedMessage.encryptedMessage bytes
		byte[] encryptedMessage = Base64.getDecoder().decode(t.getSignedMessage().getEncryptedMessage());
		// 11. compute tag with hmacSha256Key on data encryptedMessage
		byte[] computedTag = EC.hmacSha256(hmacSha256Key, encryptedMessage);
		// 12. decode token.signedMessage.tag bytes
		byte[] expectedTag = Base64.getDecoder().decode(t.getSignedMessage().getTag());
		// 13. Verify token.signedMessage.tag
		if (!Arrays.equals(expectedTag, computedTag)) {
			throw new GeneralSecurityException("cannot decrypt; invalid MAC");
		}
		// 14. derive encryption key aesCtrKey from demKey, the first half of demKey
		byte[] aesCtrKey = Arrays.copyOf(demKey, 256 / 8);
		// 15. decipher token.signedMessage.encryptedMessage
		byte[] dec = EC.aesCtr(aesCtrKey, encryptedMessage);
		return new String(dec);
	}

}
