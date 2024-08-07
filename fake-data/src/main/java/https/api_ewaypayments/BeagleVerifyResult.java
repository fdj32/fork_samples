
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlSchemaType;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for BeagleVerifyResult complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="BeagleVerifyResult"&gt;
 *   &lt;complexContent&gt;
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="Email" type="{https://api.ewaypayments.com/}BeagleVerifyStatus"/&gt;
 *         &lt;element name="Phone" type="{https://api.ewaypayments.com/}BeagleVerifyStatus"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/restriction&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "BeagleVerifyResult", propOrder = {
    "email",
    "phone"
})
public class BeagleVerifyResult {

    @XmlElement(name = "Email", required = true)
    @XmlSchemaType(name = "string")
    protected BeagleVerifyStatus email;
    @XmlElement(name = "Phone", required = true)
    @XmlSchemaType(name = "string")
    protected BeagleVerifyStatus phone;

    /**
     * Gets the value of the email property.
     * 
     * @return
     *     possible object is
     *     {@link BeagleVerifyStatus }
     *     
     */
    public BeagleVerifyStatus getEmail() {
        return email;
    }

    /**
     * Sets the value of the email property.
     * 
     * @param value
     *     allowed object is
     *     {@link BeagleVerifyStatus }
     *     
     */
    public void setEmail(BeagleVerifyStatus value) {
        this.email = value;
    }

    /**
     * Gets the value of the phone property.
     * 
     * @return
     *     possible object is
     *     {@link BeagleVerifyStatus }
     *     
     */
    public BeagleVerifyStatus getPhone() {
        return phone;
    }

    /**
     * Sets the value of the phone property.
     * 
     * @param value
     *     allowed object is
     *     {@link BeagleVerifyStatus }
     *     
     */
    public void setPhone(BeagleVerifyStatus value) {
        this.phone = value;
    }

}
