
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlEnum;
import javax.xml.bind.annotation.XmlEnumValue;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for SettlementReportMode.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * <pre>
 * &lt;simpleType name="SettlementReportMode"&gt;
 *   &lt;restriction base="{http://www.w3.org/2001/XMLSchema}string"&gt;
 *     &lt;enumeration value="SummaryOnly"/&gt;
 *     &lt;enumeration value="TransactionOnly"/&gt;
 *     &lt;enumeration value="Both"/&gt;
 *   &lt;/restriction&gt;
 * &lt;/simpleType&gt;
 * </pre>
 * 
 */
@XmlType(name = "SettlementReportMode")
@XmlEnum
public enum SettlementReportMode {

    @XmlEnumValue("SummaryOnly")
    SUMMARY_ONLY("SummaryOnly"),
    @XmlEnumValue("TransactionOnly")
    TRANSACTION_ONLY("TransactionOnly"),
    @XmlEnumValue("Both")
    BOTH("Both");
    private final String value;

    SettlementReportMode(String v) {
        value = v;
    }

    public String value() {
        return value;
    }

    public static SettlementReportMode fromValue(String v) {
        for (SettlementReportMode c: SettlementReportMode.values()) {
            if (c.value.equals(v)) {
                return c;
            }
        }
        throw new IllegalArgumentException(v);
    }

}
