package io.github.fdj32.controller;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.MediaType;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import com.google.crypto.tink.apps.paymentmethodtoken.GooglePaymentsPublicKeysManager;
import com.google.crypto.tink.apps.paymentmethodtoken.PaymentMethodTokenRecipient;

import io.github.fdj32.model.Token;
import io.github.fdj32.util.CopyTink;
import io.github.fdj32.util.EC;
import io.github.fdj32.util.TinkSimulator;

@RestController
@RequestMapping("/apis/googlepay")
public class GooglePayController {

	private static final Logger LOGGER = LoggerFactory.getLogger(GooglePayController.class);

	private static final boolean GooglePayIsProd = false;
	private static final GooglePaymentsPublicKeysManager MANAGER = GooglePayIsProd
			? GooglePaymentsPublicKeysManager.INSTANCE_PRODUCTION
			: GooglePaymentsPublicKeysManager.INSTANCE_TEST;
	private static final String RECIPIENT_PREFIX = "merchant:";
	private static final String PROTOCOL = "ECv2";
	private static final String MERCHANT_ID = "12345678901234567890";
	private static final String PRIVATE_KEY = "MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgy7oHLlY7fl8GGcHHTr5Wfp4bpBW5Ywlpq3pCc/+gEcmhRANCAASDgqhsm6SVzxOjuk/NpCIaYjVgQICz6nHrgYl5H3J6hlyFm97aQD8TOTl2X41Ktk1NVjNEbdbzDahGMMdw0AQp";

	@PostMapping(path = "/tink", produces = MediaType.APPLICATION_JSON_VALUE)
	public String tink(@RequestParam String sealedMessage) throws Exception {
		long start = System.currentTimeMillis();
		LOGGER.info("{} /tink sealedMessage: {}", start, sealedMessage);
		String json = new PaymentMethodTokenRecipient.Builder().fetchSenderVerifyingKeysWith(MANAGER)
				.recipientId(RECIPIENT_PREFIX + MERCHANT_ID).protocolVersion(PROTOCOL)
				.addRecipientPrivateKey(PRIVATE_KEY).build().unseal(sealedMessage);
		long end = System.currentTimeMillis();
		LOGGER.info("{} -> {}, cost {}, /tink unsealed: {}", start, end, (end - start), json);
		return json;
	}
	
	@PostMapping(path = "/copyTink", produces = MediaType.APPLICATION_JSON_VALUE)
	public String copyTink(@RequestParam String sealedMessage) throws Exception {
		long start = System.currentTimeMillis();
		LOGGER.info("{} /copyTink sealedMessage: {}", start, sealedMessage);
		String json = CopyTink.unseal(RECIPIENT_PREFIX + MERCHANT_ID, PRIVATE_KEY, sealedMessage);
		long end = System.currentTimeMillis();
		LOGGER.info("{} -> {}, cost {}, /copyTink unsealed: {}", start, end, (end - start), json);
		return json;
	}
	
	@PostMapping(path = "/rawEC", produces = MediaType.APPLICATION_JSON_VALUE)
	public String rawEC(@RequestParam String sealedMessage) throws Exception {
		long start = System.currentTimeMillis();
		LOGGER.info("{} /rawEC sealedMessage: {}", start, sealedMessage);
		Token t = Token.parse(sealedMessage);
		String json = EC.decrypt(t.getSignedMessage().getEncryptedMessage(), t.getSignedMessage().getEphemeralPublicKey(), PRIVATE_KEY);
		long end = System.currentTimeMillis();
		LOGGER.info("{} -> {}, cost {}, /rawEC decrypt: {}", start, end, (end - start), json);
		return json;
	}
	
	@PostMapping(path = "/tinkSimulator", produces = MediaType.APPLICATION_JSON_VALUE)
	public String tinkSimulator(@RequestParam String sealedMessage) throws Exception {
		long start = System.currentTimeMillis();
		LOGGER.info("{} /tinkSimulator sealedMessage: {}", start, sealedMessage);
		String json = TinkSimulator.unseal(MERCHANT_ID, PRIVATE_KEY, sealedMessage);
		long end = System.currentTimeMillis();
		LOGGER.info("{} -> {}, cost {}, /tinkSimulator unsealed: {}", start, end, (end - start), json);
		return json;
	}

}
