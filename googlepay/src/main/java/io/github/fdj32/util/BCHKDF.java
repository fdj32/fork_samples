package io.github.fdj32.util;

import org.bouncycastle.crypto.digests.SHA256Digest;
import org.bouncycastle.crypto.generators.HKDFBytesGenerator;
import org.bouncycastle.crypto.params.HKDFParameters;

/**
 * @see https://vimsky.com/examples/detail/java-method-org.bouncycastle.crypto.generators.HKDFBytesGenerator.generateBytes.html
 * @see https://github.com/mozilla-services/sync-crypto/blob/master/src/main/java/org/mozilla/android/sync/crypto/HKDF.java
 * @see https://mvnrepository.com/artifact/org.bouncycastle/bcprov-jdk18on
 */
public class BCHKDF {

	public static byte[] hkdfExpand(byte[] ikm, byte[] salt, byte[] info, int length) throws Exception {
		HKDFBytesGenerator hkdf = new HKDFBytesGenerator(new SHA256Digest());
		hkdf.init(new HKDFParameters(ikm, salt, info));

		byte[] okm = new byte[length];
		hkdf.generateBytes(okm, 0, length);

		return okm;
	}

	public static byte[] computeEciesHkdfSymmetricKey(final byte[] ephemeralPublicKeyBytes, final byte[] sharedSecret,
			final byte[] hkdfSalt, final byte[] hkdfInfo, int keySizeInBytes) throws Exception {
		byte[] hkdfInput = new byte[ephemeralPublicKeyBytes.length + sharedSecret.length];
		System.arraycopy(ephemeralPublicKeyBytes, 0, hkdfInput, 0, ephemeralPublicKeyBytes.length);
		System.arraycopy(sharedSecret, 0, hkdfInput, ephemeralPublicKeyBytes.length, sharedSecret.length);
		return hkdfExpand(hkdfInput, hkdfSalt, hkdfInfo, keySizeInBytes);
	}

}
