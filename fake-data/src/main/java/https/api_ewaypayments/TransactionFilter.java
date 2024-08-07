
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlSchemaType;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for TransactionFilter complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="TransactionFilter"&gt;
 *   &lt;complexContent&gt;
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="TransactionIDMatchType" type="{https://api.ewaypayments.com/}FilterMatchType"/&gt;
 *         &lt;element name="TransactionID" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="AccessCodeMatchType" type="{https://api.ewaypayments.com/}FilterMatchType"/&gt;
 *         &lt;element name="AccessCode" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CustomerIDMatchType" type="{https://api.ewaypayments.com/}FilterMatchType"/&gt;
 *         &lt;element name="CustomerID" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="InvoiceReferenceMatchType" type="{https://api.ewaypayments.com/}FilterMatchType"/&gt;
 *         &lt;element name="InvoiceReference" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="InvoiceNumberMatchType" type="{https://api.ewaypayments.com/}FilterMatchType"/&gt;
 *         &lt;element name="InvoiceNumber" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="TransactionSourceMatchType" type="{https://api.ewaypayments.com/}FilterMatchType"/&gt;
 *         &lt;element name="TransactionSource" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="SearchTextType" type="{https://api.ewaypayments.com/}FilterMatchType"/&gt;
 *         &lt;element name="SearchText" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/restriction&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "TransactionFilter", propOrder = {
    "transactionIDMatchType",
    "transactionID",
    "accessCodeMatchType",
    "accessCode",
    "customerIDMatchType",
    "customerID",
    "invoiceReferenceMatchType",
    "invoiceReference",
    "invoiceNumberMatchType",
    "invoiceNumber",
    "transactionSourceMatchType",
    "transactionSource",
    "searchTextType",
    "searchText"
})
public class TransactionFilter {

    @XmlElement(name = "TransactionIDMatchType", required = true)
    @XmlSchemaType(name = "string")
    protected FilterMatchType transactionIDMatchType;
    @XmlElement(name = "TransactionID")
    protected String transactionID;
    @XmlElement(name = "AccessCodeMatchType", required = true)
    @XmlSchemaType(name = "string")
    protected FilterMatchType accessCodeMatchType;
    @XmlElement(name = "AccessCode")
    protected String accessCode;
    @XmlElement(name = "CustomerIDMatchType", required = true)
    @XmlSchemaType(name = "string")
    protected FilterMatchType customerIDMatchType;
    @XmlElement(name = "CustomerID")
    protected String customerID;
    @XmlElement(name = "InvoiceReferenceMatchType", required = true)
    @XmlSchemaType(name = "string")
    protected FilterMatchType invoiceReferenceMatchType;
    @XmlElement(name = "InvoiceReference")
    protected String invoiceReference;
    @XmlElement(name = "InvoiceNumberMatchType", required = true)
    @XmlSchemaType(name = "string")
    protected FilterMatchType invoiceNumberMatchType;
    @XmlElement(name = "InvoiceNumber")
    protected String invoiceNumber;
    @XmlElement(name = "TransactionSourceMatchType", required = true)
    @XmlSchemaType(name = "string")
    protected FilterMatchType transactionSourceMatchType;
    @XmlElement(name = "TransactionSource")
    protected String transactionSource;
    @XmlElement(name = "SearchTextType", required = true)
    @XmlSchemaType(name = "string")
    protected FilterMatchType searchTextType;
    @XmlElement(name = "SearchText")
    protected String searchText;

    /**
     * Gets the value of the transactionIDMatchType property.
     * 
     * @return
     *     possible object is
     *     {@link FilterMatchType }
     *     
     */
    public FilterMatchType getTransactionIDMatchType() {
        return transactionIDMatchType;
    }

    /**
     * Sets the value of the transactionIDMatchType property.
     * 
     * @param value
     *     allowed object is
     *     {@link FilterMatchType }
     *     
     */
    public void setTransactionIDMatchType(FilterMatchType value) {
        this.transactionIDMatchType = value;
    }

    /**
     * Gets the value of the transactionID property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getTransactionID() {
        return transactionID;
    }

    /**
     * Sets the value of the transactionID property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setTransactionID(String value) {
        this.transactionID = value;
    }

    /**
     * Gets the value of the accessCodeMatchType property.
     * 
     * @return
     *     possible object is
     *     {@link FilterMatchType }
     *     
     */
    public FilterMatchType getAccessCodeMatchType() {
        return accessCodeMatchType;
    }

    /**
     * Sets the value of the accessCodeMatchType property.
     * 
     * @param value
     *     allowed object is
     *     {@link FilterMatchType }
     *     
     */
    public void setAccessCodeMatchType(FilterMatchType value) {
        this.accessCodeMatchType = value;
    }

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
     * Gets the value of the customerIDMatchType property.
     * 
     * @return
     *     possible object is
     *     {@link FilterMatchType }
     *     
     */
    public FilterMatchType getCustomerIDMatchType() {
        return customerIDMatchType;
    }

    /**
     * Sets the value of the customerIDMatchType property.
     * 
     * @param value
     *     allowed object is
     *     {@link FilterMatchType }
     *     
     */
    public void setCustomerIDMatchType(FilterMatchType value) {
        this.customerIDMatchType = value;
    }

    /**
     * Gets the value of the customerID property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCustomerID() {
        return customerID;
    }

    /**
     * Sets the value of the customerID property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCustomerID(String value) {
        this.customerID = value;
    }

    /**
     * Gets the value of the invoiceReferenceMatchType property.
     * 
     * @return
     *     possible object is
     *     {@link FilterMatchType }
     *     
     */
    public FilterMatchType getInvoiceReferenceMatchType() {
        return invoiceReferenceMatchType;
    }

    /**
     * Sets the value of the invoiceReferenceMatchType property.
     * 
     * @param value
     *     allowed object is
     *     {@link FilterMatchType }
     *     
     */
    public void setInvoiceReferenceMatchType(FilterMatchType value) {
        this.invoiceReferenceMatchType = value;
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
     * Gets the value of the invoiceNumberMatchType property.
     * 
     * @return
     *     possible object is
     *     {@link FilterMatchType }
     *     
     */
    public FilterMatchType getInvoiceNumberMatchType() {
        return invoiceNumberMatchType;
    }

    /**
     * Sets the value of the invoiceNumberMatchType property.
     * 
     * @param value
     *     allowed object is
     *     {@link FilterMatchType }
     *     
     */
    public void setInvoiceNumberMatchType(FilterMatchType value) {
        this.invoiceNumberMatchType = value;
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
     * Gets the value of the transactionSourceMatchType property.
     * 
     * @return
     *     possible object is
     *     {@link FilterMatchType }
     *     
     */
    public FilterMatchType getTransactionSourceMatchType() {
        return transactionSourceMatchType;
    }

    /**
     * Sets the value of the transactionSourceMatchType property.
     * 
     * @param value
     *     allowed object is
     *     {@link FilterMatchType }
     *     
     */
    public void setTransactionSourceMatchType(FilterMatchType value) {
        this.transactionSourceMatchType = value;
    }

    /**
     * Gets the value of the transactionSource property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getTransactionSource() {
        return transactionSource;
    }

    /**
     * Sets the value of the transactionSource property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setTransactionSource(String value) {
        this.transactionSource = value;
    }

    /**
     * Gets the value of the searchTextType property.
     * 
     * @return
     *     possible object is
     *     {@link FilterMatchType }
     *     
     */
    public FilterMatchType getSearchTextType() {
        return searchTextType;
    }

    /**
     * Sets the value of the searchTextType property.
     * 
     * @param value
     *     allowed object is
     *     {@link FilterMatchType }
     *     
     */
    public void setSearchTextType(FilterMatchType value) {
        this.searchTextType = value;
    }

    /**
     * Gets the value of the searchText property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getSearchText() {
        return searchText;
    }

    /**
     * Sets the value of the searchText property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setSearchText(String value) {
        this.searchText = value;
    }

}
