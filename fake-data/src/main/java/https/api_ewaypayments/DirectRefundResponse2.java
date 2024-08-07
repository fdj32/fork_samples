
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for DirectRefundResponse complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="DirectRefundResponse"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}BaseResponse"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="AuthorisationCode" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="ResponseCode" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="ResponseMessage" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="TransactionID" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="TransactionStatus" type="{http://www.w3.org/2001/XMLSchema}boolean"/&gt;
 *         &lt;element name="Verification" type="{https://api.ewaypayments.com/}VerificationResult" minOccurs="0"/&gt;
 *         &lt;element name="Customer" type="{https://api.ewaypayments.com/}DirectTokenCustomer" minOccurs="0"/&gt;
 *         &lt;element name="Refund" type="{https://api.ewaypayments.com/}Refund" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "DirectRefundResponse", propOrder = {
    "authorisationCode",
    "responseCode",
    "responseMessage",
    "transactionID",
    "transactionStatus",
    "verification",
    "customer",
    "refund"
})
public class DirectRefundResponse2
    extends BaseResponse
{

    @XmlElement(name = "AuthorisationCode")
    protected String authorisationCode;
    @XmlElement(name = "ResponseCode")
    protected String responseCode;
    @XmlElement(name = "ResponseMessage")
    protected String responseMessage;
    @XmlElement(name = "TransactionID", required = true, type = Integer.class, nillable = true)
    protected Integer transactionID;
    @XmlElement(name = "TransactionStatus", required = true, type = Boolean.class, nillable = true)
    protected Boolean transactionStatus;
    @XmlElement(name = "Verification")
    protected VerificationResult verification;
    @XmlElement(name = "Customer")
    protected DirectTokenCustomer customer;
    @XmlElement(name = "Refund")
    protected Refund refund;

    /**
     * Gets the value of the authorisationCode property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getAuthorisationCode() {
        return authorisationCode;
    }

    /**
     * Sets the value of the authorisationCode property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setAuthorisationCode(String value) {
        this.authorisationCode = value;
    }

    /**
     * Gets the value of the responseCode property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getResponseCode() {
        return responseCode;
    }

    /**
     * Sets the value of the responseCode property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setResponseCode(String value) {
        this.responseCode = value;
    }

    /**
     * Gets the value of the responseMessage property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getResponseMessage() {
        return responseMessage;
    }

    /**
     * Sets the value of the responseMessage property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setResponseMessage(String value) {
        this.responseMessage = value;
    }

    /**
     * Gets the value of the transactionID property.
     * 
     * @return
     *     possible object is
     *     {@link Integer }
     *     
     */
    public Integer getTransactionID() {
        return transactionID;
    }

    /**
     * Sets the value of the transactionID property.
     * 
     * @param value
     *     allowed object is
     *     {@link Integer }
     *     
     */
    public void setTransactionID(Integer value) {
        this.transactionID = value;
    }

    /**
     * Gets the value of the transactionStatus property.
     * 
     * @return
     *     possible object is
     *     {@link Boolean }
     *     
     */
    public Boolean isTransactionStatus() {
        return transactionStatus;
    }

    /**
     * Sets the value of the transactionStatus property.
     * 
     * @param value
     *     allowed object is
     *     {@link Boolean }
     *     
     */
    public void setTransactionStatus(Boolean value) {
        this.transactionStatus = value;
    }

    /**
     * Gets the value of the verification property.
     * 
     * @return
     *     possible object is
     *     {@link VerificationResult }
     *     
     */
    public VerificationResult getVerification() {
        return verification;
    }

    /**
     * Sets the value of the verification property.
     * 
     * @param value
     *     allowed object is
     *     {@link VerificationResult }
     *     
     */
    public void setVerification(VerificationResult value) {
        this.verification = value;
    }

    /**
     * Gets the value of the customer property.
     * 
     * @return
     *     possible object is
     *     {@link DirectTokenCustomer }
     *     
     */
    public DirectTokenCustomer getCustomer() {
        return customer;
    }

    /**
     * Sets the value of the customer property.
     * 
     * @param value
     *     allowed object is
     *     {@link DirectTokenCustomer }
     *     
     */
    public void setCustomer(DirectTokenCustomer value) {
        this.customer = value;
    }

    /**
     * Gets the value of the refund property.
     * 
     * @return
     *     possible object is
     *     {@link Refund }
     *     
     */
    public Refund getRefund() {
        return refund;
    }

    /**
     * Sets the value of the refund property.
     * 
     * @param value
     *     allowed object is
     *     {@link Refund }
     *     
     */
    public void setRefund(Refund value) {
        this.refund = value;
    }

}
