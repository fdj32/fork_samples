
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlSeeAlso;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for CaptureAuthBaseResponse complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="CaptureAuthBaseResponse"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}BaseResponse"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="ResponseCode" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="ResponseMessage" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="TransactionID" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="TransactionStatus" type="{http://www.w3.org/2001/XMLSchema}boolean"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "CaptureAuthBaseResponse", propOrder = {
    "responseCode",
    "responseMessage",
    "transactionID",
    "transactionStatus"
})
@XmlSeeAlso({
    CancelAuthorisationResponse2 .class,
    CapturePaymentResponse2 .class
})
public class CaptureAuthBaseResponse
    extends BaseResponse
{

    @XmlElement(name = "ResponseCode")
    protected String responseCode;
    @XmlElement(name = "ResponseMessage")
    protected String responseMessage;
    @XmlElement(name = "TransactionID")
    protected int transactionID;
    @XmlElement(name = "TransactionStatus")
    protected boolean transactionStatus;

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
     */
    public int getTransactionID() {
        return transactionID;
    }

    /**
     * Sets the value of the transactionID property.
     * 
     */
    public void setTransactionID(int value) {
        this.transactionID = value;
    }

    /**
     * Gets the value of the transactionStatus property.
     * 
     */
    public boolean isTransactionStatus() {
        return transactionStatus;
    }

    /**
     * Sets the value of the transactionStatus property.
     * 
     */
    public void setTransactionStatus(boolean value) {
        this.transactionStatus = value;
    }

}
