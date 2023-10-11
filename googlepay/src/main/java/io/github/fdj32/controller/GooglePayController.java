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
		LOGGER.info(sealedMessage);
		String json = new PaymentMethodTokenRecipient.Builder().fetchSenderVerifyingKeysWith(MANAGER)
				.recipientId(RECIPIENT_PREFIX + MERCHANT_ID).protocolVersion(PROTOCOL)
				.addRecipientPrivateKey(PRIVATE_KEY).build().unseal(sealedMessage);
		LOGGER.info(json);
		return json;
	}

}
