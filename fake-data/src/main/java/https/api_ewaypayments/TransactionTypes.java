
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlEnum;
import javax.xml.bind.annotation.XmlEnumValue;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for TransactionTypes.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * <pre>
 * &lt;simpleType name="TransactionTypes"&gt;
 *   &lt;restriction base="{http://www.w3.org/2001/XMLSchema}string"&gt;
 *     &lt;enumeration value="Unknown"/&gt;
 *     &lt;enumeration value="Purchase"/&gt;
 *     &lt;enumeration value="Recurring"/&gt;
 *     &lt;enumeration value="Refund"/&gt;
 *     &lt;enumeration value="MOTO"/&gt;
 *   &lt;/restriction&gt;
 * &lt;/simpleType&gt;
 * </pre>
 * 
 */
@XmlType(name = "TransactionTypes")
@XmlEnum
public enum TransactionTypes {

    @XmlEnumValue("Unknown")
    UNKNOWN("Unknown"),
    @XmlEnumValue("Purchase")
    PURCHASE("Purchase"),
    @XmlEnumValue("Recurring")
    RECURRING("Recurring"),
    @XmlEnumValue("Refund")
    REFUND("Refund"),
    MOTO("MOTO");
    private final String value;

    TransactionTypes(String v) {
        value = v;
    }

    public String value() {
        return value;
    }

    public static TransactionTypes fromValue(String v) {
        for (TransactionTypes c: TransactionTypes.values()) {
            if (c.value.equals(v)) {
                return c;
            }
        }
        throw new IllegalArgumentException(v);
    }

}
