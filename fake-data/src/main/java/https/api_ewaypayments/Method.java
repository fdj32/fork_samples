
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlEnum;
import javax.xml.bind.annotation.XmlEnumValue;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for Method.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * <pre>
 * &lt;simpleType name="Method"&gt;
 *   &lt;restriction base="{http://www.w3.org/2001/XMLSchema}string"&gt;
 *     &lt;enumeration value="ProcessPayment"/&gt;
 *     &lt;enumeration value="CreateTokenCustomer"/&gt;
 *     &lt;enumeration value="UpdateTokenCustomer"/&gt;
 *     &lt;enumeration value="TokenPayment"/&gt;
 *     &lt;enumeration value="Refund"/&gt;
 *     &lt;enumeration value="Authorise"/&gt;
 *     &lt;enumeration value="Scheduled"/&gt;
 *   &lt;/restriction&gt;
 * &lt;/simpleType&gt;
 * </pre>
 * 
 */
@XmlType(name = "Method")
@XmlEnum
public enum Method {

    @XmlEnumValue("ProcessPayment")
    PROCESS_PAYMENT("ProcessPayment"),
    @XmlEnumValue("CreateTokenCustomer")
    CREATE_TOKEN_CUSTOMER("CreateTokenCustomer"),
    @XmlEnumValue("UpdateTokenCustomer")
    UPDATE_TOKEN_CUSTOMER("UpdateTokenCustomer"),
    @XmlEnumValue("TokenPayment")
    TOKEN_PAYMENT("TokenPayment"),
    @XmlEnumValue("Refund")
    REFUND("Refund"),
    @XmlEnumValue("Authorise")
    AUTHORISE("Authorise"),
    @XmlEnumValue("Scheduled")
    SCHEDULED("Scheduled");
    private final String value;

    Method(String v) {
        value = v;
    }

    public String value() {
        return value;
    }

    public static Method fromValue(String v) {
        for (Method c: Method.values()) {
            if (c.value.equals(v)) {
                return c;
            }
        }
        throw new IllegalArgumentException(v);
    }

}
