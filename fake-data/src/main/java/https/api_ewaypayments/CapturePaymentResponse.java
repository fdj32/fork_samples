
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for anonymous complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType&gt;
 *   &lt;complexContent&gt;
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="CapturePaymentResult" type="{https://api.ewaypayments.com/}CapturePaymentResponse" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/restriction&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "", propOrder = {
    "capturePaymentResult"
})
@XmlRootElement(name = "CapturePaymentResponse")
public class CapturePaymentResponse {

    @XmlElement(name = "CapturePaymentResult")
    protected CapturePaymentResponse2 capturePaymentResult;

    /**
     * Gets the value of the capturePaymentResult property.
     * 
     * @return
     *     possible object is
     *     {@link CapturePaymentResponse2 }
     *     
     */
    public CapturePaymentResponse2 getCapturePaymentResult() {
        return capturePaymentResult;
    }

    /**
     * Sets the value of the capturePaymentResult property.
     * 
     * @param value
     *     allowed object is
     *     {@link CapturePaymentResponse2 }
     *     
     */
    public void setCapturePaymentResult(CapturePaymentResponse2 value) {
        this.capturePaymentResult = value;
    }

}
