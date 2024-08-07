
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlEnum;
import javax.xml.bind.annotation.XmlEnumValue;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for CustomView.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * <pre>
 * &lt;simpleType name="CustomView"&gt;
 *   &lt;restriction base="{http://www.w3.org/2001/XMLSchema}string"&gt;
 *     &lt;enumeration value="Default"/&gt;
 *     &lt;enumeration value="Custom"/&gt;
 *     &lt;enumeration value="Bootstrap"/&gt;
 *     &lt;enumeration value="BootstrapAmelia"/&gt;
 *     &lt;enumeration value="BootstrapCerulean"/&gt;
 *     &lt;enumeration value="BootstrapCosmo"/&gt;
 *     &lt;enumeration value="BootstrapCyborg"/&gt;
 *     &lt;enumeration value="BootstrapFlatly"/&gt;
 *     &lt;enumeration value="BootstrapJournal"/&gt;
 *     &lt;enumeration value="BootstrapReadable"/&gt;
 *     &lt;enumeration value="BootstrapSimplex"/&gt;
 *     &lt;enumeration value="BootstrapSlate"/&gt;
 *     &lt;enumeration value="BootstrapSpacelab"/&gt;
 *     &lt;enumeration value="BootstrapUnited"/&gt;
 *     &lt;enumeration value="Modal"/&gt;
 *   &lt;/restriction&gt;
 * &lt;/simpleType&gt;
 * </pre>
 * 
 */
@XmlType(name = "CustomView")
@XmlEnum
public enum CustomView {

    @XmlEnumValue("Default")
    DEFAULT("Default"),
    @XmlEnumValue("Custom")
    CUSTOM("Custom"),
    @XmlEnumValue("Bootstrap")
    BOOTSTRAP("Bootstrap"),
    @XmlEnumValue("BootstrapAmelia")
    BOOTSTRAP_AMELIA("BootstrapAmelia"),
    @XmlEnumValue("BootstrapCerulean")
    BOOTSTRAP_CERULEAN("BootstrapCerulean"),
    @XmlEnumValue("BootstrapCosmo")
    BOOTSTRAP_COSMO("BootstrapCosmo"),
    @XmlEnumValue("BootstrapCyborg")
    BOOTSTRAP_CYBORG("BootstrapCyborg"),
    @XmlEnumValue("BootstrapFlatly")
    BOOTSTRAP_FLATLY("BootstrapFlatly"),
    @XmlEnumValue("BootstrapJournal")
    BOOTSTRAP_JOURNAL("BootstrapJournal"),
    @XmlEnumValue("BootstrapReadable")
    BOOTSTRAP_READABLE("BootstrapReadable"),
    @XmlEnumValue("BootstrapSimplex")
    BOOTSTRAP_SIMPLEX("BootstrapSimplex"),
    @XmlEnumValue("BootstrapSlate")
    BOOTSTRAP_SLATE("BootstrapSlate"),
    @XmlEnumValue("BootstrapSpacelab")
    BOOTSTRAP_SPACELAB("BootstrapSpacelab"),
    @XmlEnumValue("BootstrapUnited")
    BOOTSTRAP_UNITED("BootstrapUnited"),
    @XmlEnumValue("Modal")
    MODAL("Modal");
    private final String value;

    CustomView(String v) {
        value = v;
    }

    public String value() {
        return value;
    }

    public static CustomView fromValue(String v) {
        for (CustomView c: CustomView.values()) {
            if (c.value.equals(v)) {
                return c;
            }
        }
        throw new IllegalArgumentException(v);
    }

}
