
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlSeeAlso;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for CreateAccessCodeResponse complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="CreateAccessCodeResponse"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}BaseResponse"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="AccessCode" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="Customer" type="{https://api.ewaypayments.com/}TokenCustomer" minOccurs="0"/&gt;
 *         &lt;element name="Payment" type="{https://api.ewaypayments.com/}Payment" minOccurs="0"/&gt;
 *         &lt;element name="FormActionURL" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CompleteCheckoutURL" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "CreateAccessCodeResponse", propOrder = {
    "accessCode",
    "customer",
    "payment",
    "formActionURL",
    "completeCheckoutURL"
})
@XmlSeeAlso({
    CreateAccessCodeSharedResponse2 .class
})
public class CreateAccessCodeResponse2
    extends BaseResponse
{

    @XmlElement(name = "AccessCode")
    protected String accessCode;
    @XmlElement(name = "Customer")
    protected TokenCustomer customer;
    @XmlElement(name = "Payment")
    protected Payment payment;
    @XmlElement(name = "FormActionURL")
    protected String formActionURL;
    @XmlElement(name = "CompleteCheckoutURL")
    protected String completeCheckoutURL;

    /**
     * Gets the value of the accessCode property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getAccessCode() {
        return accessCode;
    }

    /**
     * Sets the value of the accessCode property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setAccessCode(String value) {
        this.accessCode = value;
    }

    /**
     * Gets the value of the customer property.
     * 
     * @return
     *     possible object is
     *     {@link TokenCustomer }
     *     
     */
    public TokenCustomer getCustomer() {
        return customer;
    }

    /**
     * Sets the value of the customer property.
     * 
     * @param value
     *     allowed object is
     *     {@link TokenCustomer }
     *     
     */
    public void setCustomer(TokenCustomer value) {
        this.customer = value;
    }

    /**
     * Gets the value of the payment property.
     * 
     * @return
     *     possible object is
     *     {@link Payment }
     *     
     */
    public Payment getPayment() {
        return payment;
    }

    /**
     * Sets the value of the payment property.
     * 
     * @param value
     *     allowed object is
     *     {@link Payment }
     *     
     */
    public void setPayment(Payment value) {
        this.payment = value;
    }

    /**
     * Gets the value of the formActionURL property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getFormActionURL() {
        return formActionURL;
    }

    /**
     * Sets the value of the formActionURL property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setFormActionURL(String value) {
        this.formActionURL = value;
    }

    /**
     * Gets the value of the completeCheckoutURL property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCompleteCheckoutURL() {
        return completeCheckoutURL;
    }

    /**
     * Sets the value of the completeCheckoutURL property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCompleteCheckoutURL(String value) {
        this.completeCheckoutURL = value;
    }

}
