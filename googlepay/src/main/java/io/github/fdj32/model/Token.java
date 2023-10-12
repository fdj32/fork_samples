package io.github.fdj32.model;

import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

public class Token {

	private String signature;
	private IntermediateSigningKey intermediateSigningKey;
	private String protocolVersion;
	/** JSON string, not JSON object */
	private SignedMessage signedMessage;
	private String signedMessageText;

	public String getSignature() {
		return signature;
	}

	public void setSignature(String signature) {
		this.signature = signature;
	}

	public IntermediateSigningKey getIntermediateSigningKey() {
		return intermediateSigningKey;
	}

	public void setIntermediateSigningKey(IntermediateSigningKey intermediateSigningKey) {
		this.intermediateSigningKey = intermediateSigningKey;
	}

	public String getProtocolVersion() {
		return protocolVersion;
	}

	public void setProtocolVersion(String protocolVersion) {
		this.protocolVersion = protocolVersion;
	}

	public SignedMessage getSignedMessage() {
		return signedMessage;
	}

	public void setSignedMessage(SignedMessage signedMessage) {
		this.signedMessage = signedMessage;
	}

	public String getSignedMessageText() {
		return signedMessageText;
	}

	public void setSignedMessageText(String signedMessageText) {
		this.signedMessageText = signedMessageText;
	}

	public static Token parse(String s) {
		Token t = new Token();
		JsonObject jo = JsonParser.parseString(s).getAsJsonObject();
		t.setSignature(jo.get("signature").getAsString());
		t.setIntermediateSigningKey(IntermediateSigningKey.parse(jo.get("intermediateSigningKey").getAsJsonObject()));
		t.setProtocolVersion(jo.get("protocolVersion").getAsString());
		t.setSignedMessageText(jo.get("signedMessage").getAsString());
		t.setSignedMessage(SignedMessage.parse(t.getSignedMessageText()));
		return t;
	}

}
