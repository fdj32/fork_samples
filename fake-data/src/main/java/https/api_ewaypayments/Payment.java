
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlSeeAlso;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for Payment complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="Payment"&gt;
 *   &lt;complexContent&gt;
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="TotalAmount" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="InvoiceNumber" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="InvoiceDescription" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="InvoiceReference" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CurrencyCode" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/restriction&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "Payment", propOrder = {
    "totalAmount",
    "invoiceNumber",
    "invoiceDescription",
    "invoiceReference",
    "currencyCode"
})
@XmlSeeAlso({
    MposPayment.class
})
public class Payment {

    @XmlElement(name = "TotalAmount")
    protected int totalAmount;
    @XmlElement(name = "InvoiceNumber")
    protected String invoiceNumber;
    @XmlElement(name = "InvoiceDescription")
    protected String invoiceDescription;
    @XmlElement(name = "InvoiceReference")
    protected String invoiceReference;
    @XmlElement(name = "CurrencyCode")
    protected String currencyCode;

    /**
     * Gets the value of the totalAmount property.
     * 
     */
    public int getTotalAmount() {
        return totalAmount;
    }

    /**
     * Sets the value of the totalAmount property.
     * 
     */
    public void setTotalAmount(int value) {
        this.totalAmount = value;
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
     * Gets the value of the invoiceDescription property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getInvoiceDescription() {
        return invoiceDescription;
    }

    /**
     * Sets the value of the invoiceDescription property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setInvoiceDescription(String value) {
        this.invoiceDescription = value;
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
     * Gets the value of the currencyCode property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCurrencyCode() {
        return currencyCode;
    }

    /**
     * Sets the value of the currencyCode property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCurrencyCode(String value) {
        this.currencyCode = value;
    }

}
