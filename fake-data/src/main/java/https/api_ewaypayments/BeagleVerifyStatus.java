
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlEnum;
import javax.xml.bind.annotation.XmlEnumValue;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for BeagleVerifyStatus.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * <pre>
 * &lt;simpleType name="BeagleVerifyStatus"&gt;
 *   &lt;restriction base="{http://www.w3.org/2001/XMLSchema}string"&gt;
 *     &lt;enumeration value="NotVerified"/&gt;
 *     &lt;enumeration value="Attempted"/&gt;
 *     &lt;enumeration value="Verified"/&gt;
 *     &lt;enumeration value="Failed"/&gt;
 *   &lt;/restriction&gt;
 * &lt;/simpleType&gt;
 * </pre>
 * 
 */
@XmlType(name = "BeagleVerifyStatus")
@XmlEnum
public enum BeagleVerifyStatus {

    @XmlEnumValue("NotVerified")
    NOT_VERIFIED("NotVerified"),
    @XmlEnumValue("Attempted")
    ATTEMPTED("Attempted"),
    @XmlEnumValue("Verified")
    VERIFIED("Verified"),
    @XmlEnumValue("Failed")
    FAILED("Failed");
    private final String value;

    BeagleVerifyStatus(String v) {
        value = v;
    }

    public String value() {
        return value;
    }

    public static BeagleVerifyStatus fromValue(String v) {
        for (BeagleVerifyStatus c: BeagleVerifyStatus.values()) {
            if (c.value.equals(v)) {
                return c;
            }
        }
        throw new IllegalArgumentException(v);
    }

}
