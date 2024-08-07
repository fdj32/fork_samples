
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlSchemaType;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for VerificationResult complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="VerificationResult"&gt;
 *   &lt;complexContent&gt;
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="CVN" type="{https://api.ewaypayments.com/}VerificationStatus"/&gt;
 *         &lt;element name="Address" type="{https://api.ewaypayments.com/}VerificationStatus"/&gt;
 *         &lt;element name="Email" type="{https://api.ewaypayments.com/}VerificationStatus"/&gt;
 *         &lt;element name="Mobile" type="{https://api.ewaypayments.com/}VerificationStatus"/&gt;
 *         &lt;element name="Phone" type="{https://api.ewaypayments.com/}VerificationStatus"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/restriction&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "VerificationResult", propOrder = {
    "cvn",
    "address",
    "email",
    "mobile",
    "phone"
})
public class VerificationResult {

    @XmlElement(name = "CVN", required = true)
    @XmlSchemaType(name = "string")
    protected VerificationStatus cvn;
    @XmlElement(name = "Address", required = true)
    @XmlSchemaType(name = "string")
    protected VerificationStatus address;
    @XmlElement(name = "Email", required = true)
    @XmlSchemaType(name = "string")
    protected VerificationStatus email;
    @XmlElement(name = "Mobile", required = true)
    @XmlSchemaType(name = "string")
    protected VerificationStatus mobile;
    @XmlElement(name = "Phone", required = true)
    @XmlSchemaType(name = "string")
    protected VerificationStatus phone;

    /**
     * Gets the value of the cvn property.
     * 
     * @return
     *     possible object is
     *     {@link VerificationStatus }
     *     
     */
    public VerificationStatus getCVN() {
        return cvn;
    }

    /**
     * Sets the value of the cvn property.
     * 
     * @param value
     *     allowed object is
     *     {@link VerificationStatus }
     *     
     */
    public void setCVN(VerificationStatus value) {
        this.cvn = value;
    }

    /**
     * Gets the value of the address property.
     * 
     * @return
     *     possible object is
     *     {@link VerificationStatus }
     *     
     */
    public VerificationStatus getAddress() {
        return address;
    }

    /**
     * Sets the value of the address property.
     * 
     * @param value
     *     allowed object is
     *     {@link VerificationStatus }
     *     
     */
    public void setAddress(VerificationStatus value) {
        this.address = value;
    }

    /**
     * Gets the value of the email property.
     * 
     * @return
     *     possible object is
     *     {@link VerificationStatus }
     *     
     */
    public VerificationStatus getEmail() {
        return email;
    }

    /**
     * Sets the value of the email property.
     * 
     * @param value
     *     allowed object is
     *     {@link VerificationStatus }
     *     
     */
    public void setEmail(VerificationStatus value) {
        this.email = value;
    }

    /**
     * Gets the value of the mobile property.
     * 
     * @return
     *     possible object is
     *     {@link VerificationStatus }
     *     
     */
    public VerificationStatus getMobile() {
        return mobile;
    }

    /**
     * Sets the value of the mobile property.
     * 
     * @param value
     *     allowed object is
     *     {@link VerificationStatus }
     *     
     */
    public void setMobile(VerificationStatus value) {
        this.mobile = value;
    }

    /**
     * Gets the value of the phone property.
     * 
     * @return
     *     possible object is
     *     {@link VerificationStatus }
     *     
     */
    public VerificationStatus getPhone() {
        return phone;
    }

    /**
     * Sets the value of the phone property.
     * 
     * @param value
     *     allowed object is
     *     {@link VerificationStatus }
     *     
     */
    public void setPhone(VerificationStatus value) {
        this.phone = value;
    }

}
