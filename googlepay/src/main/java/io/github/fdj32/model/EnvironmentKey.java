package io.github.fdj32.model;

import java.util.ArrayList;
import java.util.List;

import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

public class EnvironmentKey {

	private String keyValue;
	private String protocolVersion;
	private String keyExpiration;

	public String getKeyValue() {
		return keyValue;
	}

	public void setKeyValue(String keyValue) {
		this.keyValue = keyValue;
	}

	public String getProtocolVersion() {
		return protocolVersion;
	}

	public void setProtocolVersion(String protocolVersion) {
		this.protocolVersion = protocolVersion;
	}

	public String getKeyExpiration() {
		return keyExpiration;
	}

	public void setKeyExpiration(String keyExpiration) {
		this.keyExpiration = keyExpiration;
	}

	public static List<EnvironmentKey> parse(String s) {
		List<EnvironmentKey> list = new ArrayList<>();
		JsonObject jo = JsonParser.parseString(s).getAsJsonObject();
		JsonArray keys = jo.get("keys").getAsJsonArray();
		keys.forEach(je -> {
			JsonObject k = je.getAsJsonObject();
			EnvironmentKey ek = new EnvironmentKey();
			ek.setKeyValue(k.get("keyValue").getAsString());
			ek.setProtocolVersion(k.get("protocolVersion").getAsString());
			if (k.has("keyExpiration")) {
				ek.setKeyExpiration(k.get("keyExpiration").getAsString());
			}
			list.add(ek);
		});
		return list;
	}

	public boolean expired() {
		if (null != keyExpiration && keyExpiration.length() > 0) {
			return Long.parseLong(keyExpiration) < System.currentTimeMillis();
		}
		return false;
	}

}
