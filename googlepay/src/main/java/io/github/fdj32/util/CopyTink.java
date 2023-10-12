package io.github.fdj32.util;

import static java.nio.charset.StandardCharsets.UTF_8;

import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.security.GeneralSecurityException;
import java.security.interfaces.ECPrivateKey;
import java.security.interfaces.ECPublicKey;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import javax.crypto.Cipher;
import javax.crypto.Mac;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

import org.apache.commons.io.IOUtils;
import org.joda.time.Instant;

import com.google.crypto.tink.HybridDecrypt;
import com.google.crypto.tink.apps.paymentmethodtoken.PaymentMethodTokenRecipientKem;
import com.google.crypto.tink.subtle.Base64;
import com.google.crypto.tink.subtle.Bytes;
import com.google.crypto.tink.subtle.EcdsaVerifyJce;
import com.google.crypto.tink.subtle.EllipticCurves;
import com.google.crypto.tink.subtle.EllipticCurves.EcdsaEncoding;
import com.google.crypto.tink.subtle.EngineFactory;
import com.google.crypto.tink.subtle.Enums.HashType;
import com.google.crypto.tink.subtle.Hkdf;
import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import com.google.gson.JsonParseException;
import com.google.gson.JsonParser;

public class CopyTink {

	/** PaymentMethodTokenConstants */
	public static final String GOOGLE_SENDER_ID = "Google";
	public static final String HMAC_SHA256_ALGO = "HmacSha256";
	public static final byte[] HKDF_EMPTY_SALT = new byte[0];
	public static final byte[] GOOGLE_CONTEXT_INFO_ECV1 = "Google".getBytes(StandardCharsets.UTF_8);
	public static final String AES_CTR_ALGO = "AES/CTR/NoPadding";
	// Zero IV is fine here because each encryption uses a unique key.
	public static final byte[] AES_CTR_ZERO_IV = new byte[16];
	public static final EllipticCurves.CurveType P256_CURVE_TYPE = EllipticCurves.CurveType.NIST_P256;
	public static final EllipticCurves.PointFormatType UNCOMPRESSED_POINT_FORMAT = EllipticCurves.PointFormatType.UNCOMPRESSED;
	public static final String PROTOCOL_VERSION_EC_V1 = "ECv1";
	public static final String PROTOCOL_VERSION_EC_V2 = "ECv2";
	public static final String PROTOCOL_VERSION_EC_V2_SIGNING_ONLY = "ECv2SigningOnly";
	public static final HashType ECDSA_HASH_SHA256 = HashType.SHA256;

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
	//private static final String RECIPIENT_PREFIX = "merchant:";
	private static final String PROTOCOL = "ECv2";

	//private static final String MERCHANT_ID = "12345678901234567890";
	//private static final String RECIPIENT_ID = RECIPIENT_PREFIX + MERCHANT_ID;
	//private static final String PRIVATE_KEY = "MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgy7oHLlY7fl8GGcHHTr5Wfp4bpBW5Ywlpq3pCc/+gEcmhRANCAASDgqhsm6SVzxOjuk/NpCIaYjVgQICz6nHrgYl5H3J6hlyFm97aQD8TOTl2X41Ktk1NVjNEbdbzDahGMMdw0AQp";

	/** URL to fetch keys for environment production. */
	public static final String KEYS_URL_PRODUCTION = "https://payments.developers.google.com/paymentmethodtoken/keys.json";
	/** URL to fetch keys for environment test. */
	public static final String KEYS_URL_TEST = "https://payments.developers.google.com/paymentmethodtoken/test/keys.json";

	/** Represents configuration regarding each protocol version. */
	enum ProtocolVersionConfig {
		EC_V1(
				/* protocolVersion= */ PROTOCOL_VERSION_EC_V1,
				/* aesCtrKeySize= */ 128 / 8,
				/* hmacSha256KeySize= */ 128 / 8,
				/* isEncryptionRequired= */ true,
				/* supportsIntermediateSigningKeys= */ false),
		EC_V2(
				/* protocolVersion= */ PROTOCOL_VERSION_EC_V2,
				/* aesCtrKeySize= */ 256 / 8,
				/* hmacSha256KeySize= */ 256 / 8,
				/* isEncryptionRequired= */ true,
				/* supportsIntermediateSigningKeys= */ true),
		EC_V2_SIGNING_ONLY(
				/* protocolVersion= */ PROTOCOL_VERSION_EC_V2_SIGNING_ONLY,
				/* aesCtrKeySize= */ 256 / 8,
				/* hmacSha256KeySize= */ 256 / 8,
				/* isEncryptionRequired= */ false,
				/* supportsIntermediateSigningKeys= */ true);

		public final String protocolVersion;
		public final int aesCtrKeySize;
		public final int hmacSha256KeySize;
		public final boolean isEncryptionRequired;
		public final boolean supportsIntermediateSigningKeys;

		ProtocolVersionConfig(String protocolVersion, int aesCtrKeySize, int hmacSha256KeySize,
				boolean isEncryptionRequired, boolean supportsIntermediateSigningKeys) {
			this.protocolVersion = protocolVersion;
			this.aesCtrKeySize = aesCtrKeySize;
			this.hmacSha256KeySize = hmacSha256KeySize;
			this.isEncryptionRequired = isEncryptionRequired;
			this.supportsIntermediateSigningKeys = supportsIntermediateSigningKeys;
		}

		public static ProtocolVersionConfig forProtocolVersion(String protocolVersion) {
			for (ProtocolVersionConfig protocolVersionConfig : ProtocolVersionConfig.values()) {
				if (protocolVersionConfig.protocolVersion.equals(protocolVersion)) {
					return protocolVersionConfig;
				}
			}
			throw new IllegalArgumentException("Unknown protocol version: " + protocolVersion);
		}
	}

	private interface SenderVerifyingKeysProvider {
		List<ECPublicKey> get(String protocolVersion) throws GeneralSecurityException;
	}

	private static final List<SenderVerifyingKeysProvider> senderVerifyingKeysProviders = new ArrayList<SenderVerifyingKeysProvider>();
	private static final List<HybridDecrypt> hybridDecrypters = new ArrayList<>();

	public static String unseal(String recipientId, String privateKeyStr, String sealedMessage) throws GeneralSecurityException {

		senderVerifyingKeysProviders.add(new SenderVerifyingKeysProvider() {
			@Override
			public List<ECPublicKey> get(String protocolVersion) throws GeneralSecurityException {
				try {
					return parseTrustedSigningKeysJson(protocolVersion, getTrustedSigningKeysJson());
				} catch (IOException e) {
					throw new GeneralSecurityException("Failed to fetch keys!", e);
				}
			}
		});

		hybridDecrypters.add(new PaymentMethodTokenHybridDecrypt(pkcs8EcPrivateKey(privateKeyStr),
				ProtocolVersionConfig.forProtocolVersion(PROTOCOL)));

		String plain = unsealECV2(recipientId, sealedMessage);
		return plain;
	}

	private static String getTrustedSigningKeysJson() throws MalformedURLException, IOException {
		return IOUtils.toString(new URL(KEYS_URL_TEST), StandardCharsets.UTF_8);
	}

	private static List<ECPublicKey> parseTrustedSigningKeysJson(String protocolVersion, String trustedSigningKeysJson)
			throws GeneralSecurityException {
		List<ECPublicKey> senderVerifyingKeys = new ArrayList<>();
		try {
			JsonArray keys = JsonParser.parseString(trustedSigningKeysJson).getAsJsonObject().get("keys")
					.getAsJsonArray();
			for (int i = 0; i < keys.size(); i++) {
				JsonObject key = keys.get(i).getAsJsonObject();
				if (protocolVersion.equals(key.get(JSON_PROTOCOL_VERSION_KEY).getAsString())) {

					if (key.has(JSON_KEY_EXPIRATION_KEY)) {
						// If message expiration is present, checking it.
						long expirationInMillis = Long.parseLong(key.get(JSON_KEY_EXPIRATION_KEY).getAsString());
						if (expirationInMillis <= Instant.now().getMillis()) {
							// Ignore expired keys
							continue;
						}
					} else if (!protocolVersion.equals(PROTOCOL_VERSION_EC_V1)) {
						// keyExpiration is required in all versions except ECv1, so if it is missing we should skip using this key.
						// In ECv1 the expiration is optional because it is assumed that the caller is respecting the HTTP cache headers 
						// and not using the trustedSigningKeysJson that are expired according to the headers.
						continue;
					}

					senderVerifyingKeys.add(x509EcPublicKey(key.get("keyValue").getAsString()));
				}
			}
		} catch (JsonParseException | IllegalStateException e) {
			throw new GeneralSecurityException("failed to extract trusted signing public keys", e);
		}
		if (senderVerifyingKeys.isEmpty()) {
			throw new GeneralSecurityException("no trusted keys are available for this protocol version");
		}
		return senderVerifyingKeys;
	}

	public static ECPrivateKey pkcs8EcPrivateKey(String pkcs8PrivateKey) throws GeneralSecurityException {
		return EllipticCurves.getEcPrivateKey(Base64.decode(pkcs8PrivateKey));
	}

	private static ECPublicKey x509EcPublicKey(String x509PublicKey) throws GeneralSecurityException {
		return EllipticCurves.getEcPublicKey(Base64.decode(x509PublicKey));
	}

	public static byte[] littleEndianLength(int len) {
		return new byte[] {
				(byte) (0xFF & len),
				(byte) (0xFF & (len >> 8)),
				(byte) (0xFF & (len >> 16)),
				(byte) (0xFF & (len >> 24)) };
	}

	private static String unsealECV2(String recipientId, String sealedMessage) throws GeneralSecurityException {
		JsonObject jsonMsg = JsonParser.parseString(sealedMessage).getAsJsonObject();
		validateECV2(jsonMsg);
		String signedMessage = verifyECV2(recipientId, jsonMsg);
		String decryptedMessage = decrypt(signedMessage);
		validateMessage(decryptedMessage);
		return decryptedMessage;
	}

	private static void validateMessage(String decryptedMessage) throws GeneralSecurityException {
		JsonObject decodedMessage;

		try {
			decodedMessage = JsonParser.parseString(decryptedMessage).getAsJsonObject();
		} catch (JsonParseException | IllegalStateException e) {
			// Message wasn't a valid JSON, so nothing to validate.
			return;
		}

		// If message expiration is present, checking it.
		if (decodedMessage.has(JSON_MESSAGE_EXPIRATION_KEY)) {
			long expirationInMillis = Long.parseLong(decodedMessage.get(JSON_MESSAGE_EXPIRATION_KEY).getAsString());
			if (expirationInMillis <= Instant.now().getMillis()) {
				throw new GeneralSecurityException("expired payload");
			}
		}
	}

	private static String decrypt(String ciphertext) throws GeneralSecurityException {
		for (HybridDecrypt hybridDecrypter : hybridDecrypters) {
			try {
				byte[] cleartext = hybridDecrypter.decrypt(ciphertext.getBytes(UTF_8), GOOGLE_CONTEXT_INFO_ECV1);
				return new String(cleartext, UTF_8);
			} catch (GeneralSecurityException e) {
				// ignored, try again
			}
		}
		throw new GeneralSecurityException("cannot decrypt");
	}

	private static void validateECV2(final JsonObject jsonMsg) throws GeneralSecurityException {
		if (!jsonMsg.has(JSON_PROTOCOL_VERSION_KEY) || !jsonMsg.has(JSON_SIGNATURE_KEY)
				|| !jsonMsg.has(JSON_SIGNED_MESSAGE_KEY) || !jsonMsg.has(JSON_INTERMEDIATE_SIGNING_KEY)
				|| jsonMsg.size() != 4) {
			throw new GeneralSecurityException(
					PROTOCOL + " message must contain exactly protocolVersion, intermediateSigningKey, signature and signedMessage");
		}
		String version = jsonMsg.get(JSON_PROTOCOL_VERSION_KEY).getAsString();
		if (!version.equals(PROTOCOL)) {
			throw new GeneralSecurityException("invalid version: " + version);
		}
	}

	private static String verifyECV2(String recipientId, final JsonObject jsonMsg) throws GeneralSecurityException {
		byte[] signature = Base64.decode(jsonMsg.get(JSON_SIGNATURE_KEY).getAsString());
		String signedMessage = jsonMsg.get(JSON_SIGNED_MESSAGE_KEY).getAsString();
		byte[] signedBytes = getSignedBytes(recipientId, PROTOCOL, signedMessage);
		verify(PROTOCOL, verifyIntermediateSigningKey(jsonMsg), Collections.singletonList(signature), signedBytes);
		return signedMessage;
	}

	private static List<SenderVerifyingKeysProvider> verifyIntermediateSigningKey(JsonObject jsonMsg)
			throws GeneralSecurityException {
		JsonObject intermediateSigningKey = jsonMsg.get(JSON_INTERMEDIATE_SIGNING_KEY).getAsJsonObject();
		validateIntermediateSigningKey(intermediateSigningKey);
		ArrayList<byte[]> signatures = new ArrayList<>();
		JsonArray signaturesJson = intermediateSigningKey.get(JSON_SIGNATURES_KEY).getAsJsonArray();
		for (int i = 0; i < signaturesJson.size(); i++) {
			signatures.add(Base64.decode(signaturesJson.get(i).getAsString()));
		}
		String signedKeyAsString = intermediateSigningKey.get(JSON_SIGNED_KEY_KEY).getAsString();
		byte[] signedBytes = toLengthValue(
				// The order of the parameters matters.
				SENDER_ID, PROTOCOL, signedKeyAsString);
		verify(PROTOCOL, senderVerifyingKeysProviders, signatures, signedBytes);
		JsonObject signedKey = JsonParser.parseString(signedKeyAsString).getAsJsonObject();
		validateSignedKey(signedKey);
		final String key = signedKey.get(JSON_KEY_VALUE_KEY).getAsString();
		SenderVerifyingKeysProvider provider = new SenderVerifyingKeysProvider() {
			@Override
			public List<ECPublicKey> get(String protocolVersion) throws GeneralSecurityException {
				if (PROTOCOL_VERSION_EC_V2.equals(protocolVersion)) {
					return Collections.singletonList(x509EcPublicKey(key));
				} else {
					return Collections.emptyList();
				}
			}
		};
		return Collections.singletonList(provider);
	}

	private static void validateSignedKey(final JsonObject signedKey) throws GeneralSecurityException {
		// Note: allowing further keys to be added so we can extend the protocol if needed in the future
		if (!signedKey.has(JSON_KEY_VALUE_KEY) || !signedKey.has(JSON_KEY_EXPIRATION_KEY)) {
			throw new GeneralSecurityException("intermediateSigningKey.signedKey must contain keyValue and keyExpiration");
		}

		// If message expiration is present, checking it.
		long expirationInMillis = Long.parseLong(signedKey.get(JSON_KEY_EXPIRATION_KEY).getAsString());
		if (expirationInMillis <= Instant.now().getMillis()) {
			throw new GeneralSecurityException("expired intermediateSigningKey");
		}
	}

	private static JsonObject validateIntermediateSigningKey(final JsonObject intermediateSigningKey)
			throws GeneralSecurityException {
		if (!intermediateSigningKey.has(JSON_SIGNATURES_KEY) || !intermediateSigningKey.has(JSON_SIGNED_KEY_KEY)
				|| intermediateSigningKey.size() != 2) {
			throw new GeneralSecurityException("intermediateSigningKey must contain exactly signedKey and signatures");
		}
		return intermediateSigningKey;
	}

	private static byte[] getSignedBytes(String recipientId, String protocolVersion, String signedMessage) throws GeneralSecurityException {
		return toLengthValue(
				// The order of the parameters matters.
				SENDER_ID, recipientId, protocolVersion, signedMessage);
	}

	private static byte[] toLengthValue(String... chunks) throws GeneralSecurityException {
		byte[] out = new byte[0];
		for (String chunk : chunks) {
			byte[] bytes = chunk.getBytes(StandardCharsets.UTF_8);
			out = Bytes.concat(out, Bytes.intToByteArray(4, bytes.length));
			out = Bytes.concat(out, bytes);
		}
		return out;
	}

	private static void verify(final String protocolVersion,
			final List<SenderVerifyingKeysProvider> senderVerifyingKeysProviders, final List<byte[]> signatures,
			final byte[] signedBytes) throws GeneralSecurityException {
		boolean verified = false;
		for (SenderVerifyingKeysProvider verifyingKeysProvider : senderVerifyingKeysProviders) {
			for (ECPublicKey publicKey : verifyingKeysProvider.get(protocolVersion)) {
				EcdsaVerifyJce verifier = new EcdsaVerifyJce(publicKey, ECDSA_HASH_SHA256, EcdsaEncoding.DER);
				for (byte[] signature : signatures) {
					try {
						verifier.verify(signature, signedBytes);
						// No exception means the signature is valid.
						verified = true;
					} catch (GeneralSecurityException e) {
						// ignored, try again
					}
				}
			}
		}
		if (!verified) {
			throw new GeneralSecurityException("cannot verify signature");
		}
	}

	static class PaymentMethodTokenHybridDecrypt implements HybridDecrypt {
		private final PaymentMethodTokenRecipientKem recipientKem;
		private final ProtocolVersionConfig protocolVersionConfig;

		PaymentMethodTokenHybridDecrypt(final ECPrivateKey recipientPrivateKey,
				ProtocolVersionConfig protocolVersionConfig) throws GeneralSecurityException {
			this(new PaymentMethodTokenRecipientKem() {
				@Override
				public byte[] computeSharedSecret(final byte[] ephemeralPublicKey) throws GeneralSecurityException {
					ECPublicKey publicKey = EllipticCurves.getEcPublicKey(recipientPrivateKey.getParams(),
							UNCOMPRESSED_POINT_FORMAT, ephemeralPublicKey);
					return EllipticCurves.computeSharedSecret(recipientPrivateKey, publicKey);
				}
			}, protocolVersionConfig);
		}

		PaymentMethodTokenHybridDecrypt(final PaymentMethodTokenRecipientKem recipientKem,
				ProtocolVersionConfig protocolVersionConfig) {
			this.recipientKem = recipientKem;
			this.protocolVersionConfig = protocolVersionConfig;
		}

		@Override
		public byte[] decrypt(final byte[] ciphertext, final byte[] contextInfo) throws GeneralSecurityException {
			try {
				JsonObject json = JsonParser.parseString(new String(ciphertext, UTF_8)).getAsJsonObject();
				validate(json);
				byte[] demKey = kem(json, contextInfo);
				return dem(json, demKey);
			} catch (JsonParseException | IllegalStateException e) {
				throw new GeneralSecurityException("cannot decrypt; failed to parse JSON", e);
			}
		}

		private byte[] kem(JsonObject json, final byte[] contextInfo) throws GeneralSecurityException {
			int demKeySize = protocolVersionConfig.aesCtrKeySize + protocolVersionConfig.hmacSha256KeySize;
			byte[] ephemeralPublicKey = Base64.decode(json.get(JSON_EPHEMERAL_PUBLIC_KEY).getAsString());
			byte[] sharedSecret = recipientKem.computeSharedSecret(ephemeralPublicKey);
			return Hkdf.computeEciesHkdfSymmetricKey(ephemeralPublicKey, sharedSecret, HMAC_SHA256_ALGO,
					HKDF_EMPTY_SALT, contextInfo, demKeySize);
		}

		private byte[] dem(JsonObject json, final byte[] demKey) throws GeneralSecurityException {
			byte[] hmacSha256Key = Arrays.copyOfRange(demKey, protocolVersionConfig.aesCtrKeySize, demKey.length);
			byte[] encryptedMessage = Base64.decode(json.get(JSON_ENCRYPTED_MESSAGE_KEY).getAsString());
			byte[] computedTag = hmacSha256(hmacSha256Key, encryptedMessage);
			byte[] expectedTag = Base64.decode(json.get(JSON_TAG_KEY).getAsString());
			if (!Bytes.equal(expectedTag, computedTag)) {
				throw new GeneralSecurityException("cannot decrypt; invalid MAC");
			}
			byte[] aesCtrKey = Arrays.copyOf(demKey, protocolVersionConfig.aesCtrKeySize);
			return aesCtr(aesCtrKey, encryptedMessage);
		}

		private void validate(JsonObject payload) throws GeneralSecurityException {
			if (!payload.has(JSON_ENCRYPTED_MESSAGE_KEY) || !payload.has(JSON_TAG_KEY)
					|| !payload.has(JSON_EPHEMERAL_PUBLIC_KEY) || payload.size() != 3) {
				throw new GeneralSecurityException("The payload must contain exactly encryptedMessage, tag and ephemeralPublicKey");
			}
		}
	}

	private static byte[] hmacSha256(final byte[] macKey, final byte[] encryptedMessage)
			throws GeneralSecurityException {
		SecretKeySpec key = new SecretKeySpec(macKey, HMAC_SHA256_ALGO);
		Mac mac = EngineFactory.MAC.getInstance(HMAC_SHA256_ALGO);
		mac.init(key);
		return mac.doFinal(encryptedMessage);
	}

	private static byte[] aesCtr(final byte[] encryptionKey, final byte[] message) throws GeneralSecurityException {
		Cipher cipher = EngineFactory.CIPHER.getInstance(AES_CTR_ALGO);
		cipher.init(Cipher.ENCRYPT_MODE, new SecretKeySpec(encryptionKey, "AES"), new IvParameterSpec(AES_CTR_ZERO_IV));
		return cipher.doFinal(message);
	}

}
