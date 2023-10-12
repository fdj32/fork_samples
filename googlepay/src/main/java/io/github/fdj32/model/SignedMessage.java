package io.github.fdj32.model;

import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

public class SignedMessage {

	private String encryptedMessage;
	private String ephemeralPublicKey;
	private String tag;

	public String getEncryptedMessage() {
		return encryptedMessage;
	}

	public void setEncryptedMessage(String encryptedMessage) {
		this.encryptedMessage = encryptedMessage;
	}

	public String getEphemeralPublicKey() {
		return ephemeralPublicKey;
	}

	public void setEphemeralPublicKey(String ephemeralPublicKey) {
		this.ephemeralPublicKey = ephemeralPublicKey;
	}

	public String getTag() {
		return tag;
	}

	public void setTag(String tag) {
		this.tag = tag;
	}

	public static SignedMessage parse(String s) {
		SignedMessage m = new SignedMessage();
		JsonObject jo = JsonParser.parseString(s).getAsJsonObject();
		m.setEncryptedMessage(jo.get("encryptedMessage").getAsString());
		m.setEphemeralPublicKey(jo.get("ephemeralPublicKey").getAsString());
		m.setTag(jo.get("tag").getAsString());
		return m;
	}

}
