
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlSeeAlso;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for CaptureAuthBaseRequest complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="CaptureAuthBaseRequest"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}BaseRequest"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="TransactionID" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "CaptureAuthBaseRequest", propOrder = {
    "transactionID"
})
@XmlSeeAlso({
    CancelAuthorisationRequest.class,
    CapturePaymentRequest.class
})
public class CaptureAuthBaseRequest
    extends BaseRequest
{

    @XmlElement(name = "TransactionID")
    protected int transactionID;

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

}
