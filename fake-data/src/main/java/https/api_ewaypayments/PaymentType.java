
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlEnum;
import javax.xml.bind.annotation.XmlEnumValue;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for PaymentType.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * <pre>
 * &lt;simpleType name="PaymentType"&gt;
 *   &lt;restriction base="{http://www.w3.org/2001/XMLSchema}string"&gt;
 *     &lt;enumeration value="None"/&gt;
 *     &lt;enumeration value="CreditCard"/&gt;
 *     &lt;enumeration value="PayPal"/&gt;
 *     &lt;enumeration value="MasterPass"/&gt;
 *     &lt;enumeration value="VisaCheckout"/&gt;
 *     &lt;enumeration value="AmexExpressCheckout"/&gt;
 *     &lt;enumeration value="ApplePay"/&gt;
 *     &lt;enumeration value="DirectDebit"/&gt;
 *     &lt;enumeration value="UnionPay"/&gt;
 *   &lt;/restriction&gt;
 * &lt;/simpleType&gt;
 * </pre>
 * 
 */
@XmlType(name = "PaymentType")
@XmlEnum
public enum PaymentType {

    @XmlEnumValue("None")
    NONE("None"),
    @XmlEnumValue("CreditCard")
    CREDIT_CARD("CreditCard"),
    @XmlEnumValue("PayPal")
    PAY_PAL("PayPal"),
    @XmlEnumValue("MasterPass")
    MASTER_PASS("MasterPass"),
    @XmlEnumValue("VisaCheckout")
    VISA_CHECKOUT("VisaCheckout"),
    @XmlEnumValue("AmexExpressCheckout")
    AMEX_EXPRESS_CHECKOUT("AmexExpressCheckout"),
    @XmlEnumValue("ApplePay")
    APPLE_PAY("ApplePay"),
    @XmlEnumValue("DirectDebit")
    DIRECT_DEBIT("DirectDebit"),
    @XmlEnumValue("UnionPay")
    UNION_PAY("UnionPay");
    private final String value;

    PaymentType(String v) {
        value = v;
    }

    public String value() {
        return value;
    }

    public static PaymentType fromValue(String v) {
        for (PaymentType c: PaymentType.values()) {
            if (c.value.equals(v)) {
                return c;
            }
        }
        throw new IllegalArgumentException(v);
    }

}
