package io.github.fdj32.util;

import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.security.KeyFactory;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.Signature;
import java.security.interfaces.ECPrivateKey;
import java.security.interfaces.ECPublicKey;
import java.security.spec.ECField;
import java.security.spec.ECFieldFp;
import java.security.spec.ECParameterSpec;
import java.security.spec.ECPoint;
import java.security.spec.ECPrivateKeySpec;
import java.security.spec.ECPublicKeySpec;
import java.security.spec.EllipticCurve;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;
import java.util.Arrays;
import java.util.Base64;

import javax.crypto.Cipher;
import javax.crypto.KeyAgreement;
import javax.crypto.Mac;
import javax.crypto.NullCipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

import org.apache.commons.codec.binary.Hex;

public class EC {

	private static final String SHA256withECDSA = "SHA256withECDSA";
	private static final String EC = "EC";
	private static final String ECDH = "ECDH";
	private static final String HMAC_SHA256_ALGO = "HmacSha256";
	private static final String AES_CTR_ALGO = "AES/CTR/NoPadding";
	private static final byte[] AES_CTR_ZERO_IV = new byte[16];
	private static final byte[] HKDF_EMPTY_SALT = new byte[0];
	private static final byte[] GOOGLE_CONTEXT_INFO_ECV1 = "Google".getBytes(StandardCharsets.UTF_8);

	public static byte[] sign(byte[] data, PrivateKey priKey) throws Exception {
		Signature sig = Signature.getInstance(SHA256withECDSA);
		sig.initSign(priKey);
		sig.update(data);
		return sig.sign();
	}

	public static String sign(String data, PrivateKey priKey) throws Exception {
		byte[] plain = Hex.decodeHex(data);
		byte[] signed = sign(plain, priKey);
		return Hex.encodeHexString(signed);
	}

	public static boolean verify(byte[] data, byte[] signature, PublicKey pubKey) throws Exception {
		Signature sig = Signature.getInstance(SHA256withECDSA);
		sig.initVerify(pubKey);
		sig.update(data);
		return sig.verify(signature);
	}

	public static boolean verify(String data, String signature, PublicKey pubKey) throws Exception {
		return verify(Hex.decodeHex(data), Hex.decodeHex(signature), pubKey);
	}

	public static byte[] encrypt(byte[] data, ECPublicKey pubKey) throws Exception {
		ECPublicKeySpec spec = new ECPublicKeySpec(pubKey.getW(), pubKey.getParams());
		Cipher cipher = new NullCipher();
		cipher.init(Cipher.ENCRYPT_MODE, pubKey, spec.getParams());
		return cipher.doFinal(data);
	}

	public static String encrypt(String data, ECPublicKey pubKey) throws Exception {
		return Hex.encodeHexString(encrypt(data.getBytes(), pubKey));
	}

	public static byte[] decrypt(byte[] encBytes, ECPrivateKey priKey) throws Exception {
		ECPrivateKeySpec spec = new ECPrivateKeySpec(priKey.getS(), priKey.getParams());
		Cipher cipher = new NullCipher();
		cipher.init(Cipher.DECRYPT_MODE, priKey, spec.getParams());
		return cipher.doFinal(encBytes);
	}

	public static String decrypt(String cipherText, ECPrivateKey priKey) throws Exception {
		return new String(decrypt(Hex.decodeHex(cipherText), priKey));
	}

	public static ECPublicKey str2ECPubKey(String str) throws Exception {
		X509EncodedKeySpec spec = new X509EncodedKeySpec(Base64.getDecoder().decode(str));
		KeyFactory kf = KeyFactory.getInstance(EC);
		return (ECPublicKey) kf.generatePublic(spec);
	}

	public static ECPrivateKey str2ECPriKey(String str) throws Exception {
		PKCS8EncodedKeySpec spec = new PKCS8EncodedKeySpec(Base64.getDecoder().decode(str));
		KeyFactory kf = KeyFactory.getInstance(EC);
		return (ECPrivateKey) kf.generatePrivate(spec);
	}

	public static ECPublicKey generatePublic(String ephemeralPublicKey, String merchantPrivateKey) throws Exception {
		ECPrivateKey myPrivateKey = str2ECPriKey(merchantPrivateKey);
		ECParameterSpec ecpSpec = myPrivateKey.getParams();
		EllipticCurve curve = ecpSpec.getCurve();
		ECField field = curve.getField();
		BigInteger modulus = ((ECFieldFp) field).getP();
		int coordinateSize = (modulus.subtract(BigInteger.ONE).bitLength() + 7) / 8;

		byte[] encoded = Base64.getDecoder().decode(ephemeralPublicKey);
		BigInteger x = new BigInteger(1, Arrays.copyOfRange(encoded, 1, coordinateSize + 1));
		BigInteger y = new BigInteger(1, Arrays.copyOfRange(encoded, coordinateSize + 1, encoded.length));
		ECPoint point = new ECPoint(x, y);

		ECPublicKeySpec pubSpec = new ECPublicKeySpec(point, ecpSpec);
		KeyFactory kf = KeyFactory.getInstance("EC");
		return (ECPublicKey) kf.generatePublic(pubSpec);
	}

	public static byte[] computeSharedSecret(ECPublicKey pubKey, ECPrivateKey priKey) throws Exception {
		KeyAgreement ka = KeyAgreement.getInstance(ECDH);
		ka.init(priKey);
		ka.doPhase(pubKey, true /* lastPhase */);
		return ka.generateSecret();
	}

	public static byte[] hmacSha256(final byte[] macKey, final byte[] encryptedMessage) throws Exception {
		SecretKeySpec key = new SecretKeySpec(macKey, HMAC_SHA256_ALGO);
		Mac mac = Mac.getInstance(HMAC_SHA256_ALGO);
		mac.init(key);
		return mac.doFinal(encryptedMessage);
	}

	public static byte[] aesCtr(final byte[] encryptionKey, final byte[] message) throws Exception {
		Cipher cipher = Cipher.getInstance(AES_CTR_ALGO);
		cipher.init(Cipher.DECRYPT_MODE, new SecretKeySpec(encryptionKey, "AES"), new IvParameterSpec(AES_CTR_ZERO_IV));
		return cipher.doFinal(message);
	}

	public static String decrypt(String encryptedMessageStr, String ephemeralPublicKeyStr, String merchantPrivateKeyStr)
			throws Exception {
		ECPrivateKey merchantPrivateKey = str2ECPriKey(merchantPrivateKeyStr);
		ECPublicKey ephemeralPublicKey = generatePublic(ephemeralPublicKeyStr, merchantPrivateKeyStr);
		byte[] sharedSecret = computeSharedSecret(ephemeralPublicKey, merchantPrivateKey);
		int demKeySize = 256 / 8 + 256 / 8;
		byte[] demKey = Hkdf.computeEciesHkdfSymmetricKey(Base64.getDecoder().decode(ephemeralPublicKeyStr),
				sharedSecret, HMAC_SHA256_ALGO, HKDF_EMPTY_SALT, GOOGLE_CONTEXT_INFO_ECV1, demKeySize);
		byte[] aesCtrKey = Arrays.copyOf(demKey, 256 / 8);
		byte[] encryptedMessage = Base64.getDecoder().decode(encryptedMessageStr);
		return new String(aesCtr(aesCtrKey, encryptedMessage));
	}

}
