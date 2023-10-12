package io.github.fdj32.model;

import java.util.ArrayList;
import java.util.List;

import com.google.gson.JsonArray;
import com.google.gson.JsonObject;

public class IntermediateSigningKey {

	/** JSON string, not JSON object */
	private SignedKey signedKey;
	private String signedKeyText;
	private List<String> signatures;

	public SignedKey getSignedKey() {
		return signedKey;
	}

	public void setSignedKey(SignedKey signedKey) {
		this.signedKey = signedKey;
	}

	public String getSignedKeyText() {
		return signedKeyText;
	}

	public void setSignedKeyText(String signedKeyText) {
		this.signedKeyText = signedKeyText;
	}

	public List<String> getSignatures() {
		return signatures;
	}

	public void setSignatures(List<String> signatures) {
		this.signatures = signatures;
	}

	public static IntermediateSigningKey parse(JsonObject jo) {
		IntermediateSigningKey k = new IntermediateSigningKey();
		k.setSignedKeyText(jo.get("signedKey").getAsString());
		k.setSignedKey(SignedKey.parse(k.getSignedKeyText()));
		List<String> signatures = new ArrayList<>();
		JsonArray signaturesJson = jo.get("signatures").getAsJsonArray();
		for (int i = 0; i < signaturesJson.size(); i++) {
			signatures.add(signaturesJson.get(i).getAsString());
		}
		k.setSignatures(signatures);
		return k;
	}

}
