
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlSeeAlso;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for MposPayment complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="MposPayment"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}Payment"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="AuthorisationID" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="STAN" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="ReceiptId" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="Receipt" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="ResponseCode" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="ResponseText" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="MerchantID" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="TerminalID" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="PosReference" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="SettlementDate" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="ReceiptGUID" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="MposDeviceId" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "MposPayment", propOrder = {
    "authorisationID",
    "stan",
    "receiptId",
    "receipt",
    "responseCode",
    "responseText",
    "merchantID",
    "terminalID",
    "posReference",
    "settlementDate",
    "receiptGUID",
    "mposDeviceId"
})
@XmlSeeAlso({
    Refund.class
})
public class MposPayment
    extends Payment
{

    @XmlElement(name = "AuthorisationID")
    protected String authorisationID;
    @XmlElement(name = "STAN")
    protected String stan;
    @XmlElement(name = "ReceiptId")
    protected String receiptId;
    @XmlElement(name = "Receipt")
    protected String receipt;
    @XmlElement(name = "ResponseCode")
    protected String responseCode;
    @XmlElement(name = "ResponseText")
    protected String responseText;
    @XmlElement(name = "MerchantID")
    protected String merchantID;
    @XmlElement(name = "TerminalID")
    protected String terminalID;
    @XmlElement(name = "PosReference")
    protected String posReference;
    @XmlElement(name = "SettlementDate")
    protected String settlementDate;
    @XmlElement(name = "ReceiptGUID")
    protected String receiptGUID;
    @XmlElement(name = "MposDeviceId")
    protected String mposDeviceId;

    /**
     * Gets the value of the authorisationID property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getAuthorisationID() {
        return authorisationID;
    }

    /**
     * Sets the value of the authorisationID property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setAuthorisationID(String value) {
        this.authorisationID = value;
    }

    /**
     * Gets the value of the stan property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getSTAN() {
        return stan;
    }

    /**
     * Sets the value of the stan property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setSTAN(String value) {
        this.stan = value;
    }

    /**
     * Gets the value of the receiptId property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getReceiptId() {
        return receiptId;
    }

    /**
     * Sets the value of the receiptId property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setReceiptId(String value) {
        this.receiptId = value;
    }

    /**
     * Gets the value of the receipt property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getReceipt() {
        return receipt;
    }

    /**
     * Sets the value of the receipt property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setReceipt(String value) {
        this.receipt = value;
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
     * Gets the value of the responseText property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getResponseText() {
        return responseText;
    }

    /**
     * Sets the value of the responseText property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setResponseText(String value) {
        this.responseText = value;
    }

    /**
     * Gets the value of the merchantID property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getMerchantID() {
        return merchantID;
    }

    /**
     * Sets the value of the merchantID property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setMerchantID(String value) {
        this.merchantID = value;
    }

    /**
     * Gets the value of the terminalID property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getTerminalID() {
        return terminalID;
    }

    /**
     * Sets the value of the terminalID property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setTerminalID(String value) {
        this.terminalID = value;
    }

    /**
     * Gets the value of the posReference property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getPosReference() {
        return posReference;
    }

    /**
     * Sets the value of the posReference property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setPosReference(String value) {
        this.posReference = value;
    }

    /**
     * Gets the value of the settlementDate property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getSettlementDate() {
        return settlementDate;
    }

    /**
     * Sets the value of the settlementDate property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setSettlementDate(String value) {
        this.settlementDate = value;
    }

    /**
     * Gets the value of the receiptGUID property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getReceiptGUID() {
        return receiptGUID;
    }

    /**
     * Sets the value of the receiptGUID property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setReceiptGUID(String value) {
        this.receiptGUID = value;
    }

    /**
     * Gets the value of the mposDeviceId property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getMposDeviceId() {
        return mposDeviceId;
    }

    /**
     * Sets the value of the mposDeviceId property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setMposDeviceId(String value) {
        this.mposDeviceId = value;
    }

}
