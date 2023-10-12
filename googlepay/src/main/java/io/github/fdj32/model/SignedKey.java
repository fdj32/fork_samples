package io.github.fdj32.model;

import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

public class SignedKey {

	private String keyValue;
	private String keyExpiration;

	public String getKeyValue() {
		return keyValue;
	}

	public void setKeyValue(String keyValue) {
		this.keyValue = keyValue;
	}

	public String getKeyExpiration() {
		return keyExpiration;
	}

	public void setKeyExpiration(String keyExpiration) {
		this.keyExpiration = keyExpiration;
	}

	public static SignedKey parse(String s) {
		SignedKey k = new SignedKey();
		JsonObject jo = JsonParser.parseString(s).getAsJsonObject();
		k.setKeyValue(jo.get("keyValue").getAsString());
		k.setKeyExpiration(jo.get("keyExpiration").getAsString());
		return k;
	}
}
