
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlEnum;
import javax.xml.bind.annotation.XmlEnumValue;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for VerificationStatus.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * <pre>
 * &lt;simpleType name="VerificationStatus"&gt;
 *   &lt;restriction base="{http://www.w3.org/2001/XMLSchema}string"&gt;
 *     &lt;enumeration value="Unchecked"/&gt;
 *     &lt;enumeration value="Valid"/&gt;
 *     &lt;enumeration value="Invalid"/&gt;
 *   &lt;/restriction&gt;
 * &lt;/simpleType&gt;
 * </pre>
 * 
 */
@XmlType(name = "VerificationStatus")
@XmlEnum
public enum VerificationStatus {

    @XmlEnumValue("Unchecked")
    UNCHECKED("Unchecked"),
    @XmlEnumValue("Valid")
    VALID("Valid"),
    @XmlEnumValue("Invalid")
    INVALID("Invalid");
    private final String value;

    VerificationStatus(String v) {
        value = v;
    }

    public String value() {
        return value;
    }

    public static VerificationStatus fromValue(String v) {
        for (VerificationStatus c: VerificationStatus.values()) {
            if (c.value.equals(v)) {
                return c;
            }
        }
        throw new IllegalArgumentException(v);
    }

}
