
package https.api_ewaypayments;

import java.math.BigDecimal;
import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for TransactionResult complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="TransactionResult"&gt;
 *   &lt;complexContent&gt;
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="AuthorisationCode" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="ResponseCode" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="ResponseMessage" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="InvoiceNumber" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="InvoiceReference" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="TotalAmount" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="TransactionID" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="TransactionStatus" type="{http://www.w3.org/2001/XMLSchema}boolean"/&gt;
 *         &lt;element name="TokenCustomerID" type="{http://www.w3.org/2001/XMLSchema}long"/&gt;
 *         &lt;element name="BeagleScore" type="{http://www.w3.org/2001/XMLSchema}decimal"/&gt;
 *         &lt;element name="Options" type="{https://api.ewaypayments.com/}ArrayOfOption" minOccurs="0"/&gt;
 *         &lt;element name="Verification" type="{https://api.ewaypayments.com/}VerificationResult" minOccurs="0"/&gt;
 *         &lt;element name="BeagleVerification" type="{https://api.ewaypayments.com/}BeagleVerifyResult" minOccurs="0"/&gt;
 *         &lt;element name="Customer" type="{https://api.ewaypayments.com/}Customer" minOccurs="0"/&gt;
 *         &lt;element name="CustomerNote" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="ShippingAddress" type="{https://api.ewaypayments.com/}ShippingAddress" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/restriction&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "TransactionResult", propOrder = {
    "authorisationCode",
    "responseCode",
    "responseMessage",
    "invoiceNumber",
    "invoiceReference",
    "totalAmount",
    "transactionID",
    "transactionStatus",
    "tokenCustomerID",
    "beagleScore",
    "options",
    "verification",
    "beagleVerification",
    "customer",
    "customerNote",
    "shippingAddress"
})
public class TransactionResult {

    @XmlElement(name = "AuthorisationCode")
    protected String authorisationCode;
    @XmlElement(name = "ResponseCode")
    protected String responseCode;
    @XmlElement(name = "ResponseMessage")
    protected String responseMessage;
    @XmlElement(name = "InvoiceNumber")
    protected String invoiceNumber;
    @XmlElement(name = "InvoiceReference")
    protected String invoiceReference;
    @XmlElement(name = "TotalAmount", required = true, type = Integer.class, nillable = true)
    protected Integer totalAmount;
    @XmlElement(name = "TransactionID", required = true, type = Integer.class, nillable = true)
    protected Integer transactionID;
    @XmlElement(name = "TransactionStatus", required = true, type = Boolean.class, nillable = true)
    protected Boolean transactionStatus;
    @XmlElement(name = "TokenCustomerID", required = true, type = Long.class, nillable = true)
    protected Long tokenCustomerID;
    @XmlElement(name = "BeagleScore", required = true, nillable = true)
    protected BigDecimal beagleScore;
    @XmlElement(name = "Options")
    protected ArrayOfOption options;
    @XmlElement(name = "Verification")
    protected VerificationResult verification;
    @XmlElement(name = "BeagleVerification")
    protected BeagleVerifyResult beagleVerification;
    @XmlElement(name = "Customer")
    protected Customer customer;
    @XmlElement(name = "CustomerNote")
    protected String customerNote;
    @XmlElement(name = "ShippingAddress")
    protected ShippingAddress shippingAddress;

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
     * Gets the value of the invoiceNumber property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getInvoiceNumber() {
        return invoiceNumber;
    }

    /**
     * Sets the value of the invoiceNumber property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setInvoiceNumber(String value) {
        this.invoiceNumber = value;
    }

    /**
     * Gets the value of the invoiceReference property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getInvoiceReference() {
        return invoiceReference;
    }

    /**
     * Sets the value of the invoiceReference property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setInvoiceReference(String value) {
        this.invoiceReference = value;
    }

    /**
     * Gets the value of the totalAmount property.
     * 
     * @return
     *     possible object is
     *     {@link Integer }
     *     
     */
    public Integer getTotalAmount() {
        return totalAmount;
    }

    /**
     * Sets the value of the totalAmount property.
     * 
     * @param value
     *     allowed object is
     *     {@link Integer }
     *     
     */
    public void setTotalAmount(Integer value) {
        this.totalAmount = value;
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
     * Gets the value of the tokenCustomerID property.
     * 
     * @return
     *     possible object is
     *     {@link Long }
     *     
     */
    public Long getTokenCustomerID() {
        return tokenCustomerID;
    }

    /**
     * Sets the value of the tokenCustomerID property.
     * 
     * @param value
     *     allowed object is
     *     {@link Long }
     *     
     */
    public void setTokenCustomerID(Long value) {
        this.tokenCustomerID = value;
    }

    /**
     * Gets the value of the beagleScore property.
     * 
     * @return
     *     possible object is
     *     {@link BigDecimal }
     *     
     */
    public BigDecimal getBeagleScore() {
        return beagleScore;
    }

    /**
     * Sets the value of the beagleScore property.
     * 
     * @param value
     *     allowed object is
     *     {@link BigDecimal }
     *     
     */
    public void setBeagleScore(BigDecimal value) {
        this.beagleScore = value;
    }

    /**
     * Gets the value of the options property.
     * 
     * @return
     *     possible object is
     *     {@link ArrayOfOption }
     *     
     */
    public ArrayOfOption getOptions() {
        return options;
    }

    /**
     * Sets the value of the options property.
     * 
     * @param value
     *     allowed object is
     *     {@link ArrayOfOption }
     *     
     */
    public void setOptions(ArrayOfOption value) {
        this.options = value;
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
     * Gets the value of the beagleVerification property.
     * 
     * @return
     *     possible object is
     *     {@link BeagleVerifyResult }
     *     
     */
    public BeagleVerifyResult getBeagleVerification() {
        return beagleVerification;
    }

    /**
     * Sets the value of the beagleVerification property.
     * 
     * @param value
     *     allowed object is
     *     {@link BeagleVerifyResult }
     *     
     */
    public void setBeagleVerification(BeagleVerifyResult value) {
        this.beagleVerification = value;
    }

    /**
     * Gets the value of the customer property.
     * 
     * @return
     *     possible object is
     *     {@link Customer }
     *     
     */
    public Customer getCustomer() {
        return customer;
    }

    /**
     * Sets the value of the customer property.
     * 
     * @param value
     *     allowed object is
     *     {@link Customer }
     *     
     */
    public void setCustomer(Customer value) {
        this.customer = value;
    }

    /**
     * Gets the value of the customerNote property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCustomerNote() {
        return customerNote;
    }

    /**
     * Sets the value of the customerNote property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCustomerNote(String value) {
        this.customerNote = value;
    }

    /**
     * Gets the value of the shippingAddress property.
     * 
     * @return
     *     possible object is
     *     {@link ShippingAddress }
     *     
     */
    public ShippingAddress getShippingAddress() {
        return shippingAddress;
    }

    /**
     * Sets the value of the shippingAddress property.
     * 
     * @param value
     *     allowed object is
     *     {@link ShippingAddress }
     *     
     */
    public void setShippingAddress(ShippingAddress value) {
        this.shippingAddress = value;
    }

}
