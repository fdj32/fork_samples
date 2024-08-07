
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlEnum;
import javax.xml.bind.annotation.XmlEnumValue;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for FilterMatchType.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * <pre>
 * &lt;simpleType name="FilterMatchType"&gt;
 *   &lt;restriction base="{http://www.w3.org/2001/XMLSchema}string"&gt;
 *     &lt;enumeration value="Undefined"/&gt;
 *     &lt;enumeration value="Equals"/&gt;
 *     &lt;enumeration value="Contains"/&gt;
 *     &lt;enumeration value="StartsWith"/&gt;
 *   &lt;/restriction&gt;
 * &lt;/simpleType&gt;
 * </pre>
 * 
 */
@XmlType(name = "FilterMatchType")
@XmlEnum
public enum FilterMatchType {

    @XmlEnumValue("Undefined")
    UNDEFINED("Undefined"),
    @XmlEnumValue("Equals")
    EQUALS("Equals"),
    @XmlEnumValue("Contains")
    CONTAINS("Contains"),
    @XmlEnumValue("StartsWith")
    STARTS_WITH("StartsWith");
    private final String value;

    FilterMatchType(String v) {
        value = v;
    }

    public String value() {
        return value;
    }

    public static FilterMatchType fromValue(String v) {
        for (FilterMatchType c: FilterMatchType.values()) {
            if (c.value.equals(v)) {
                return c;
            }
        }
        throw new IllegalArgumentException(v);
    }

}
