
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for CreateAccessCodeSharedResponse complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="CreateAccessCodeSharedResponse"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}CreateAccessCodeResponse"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="SharedPaymentUrl" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "CreateAccessCodeSharedResponse", propOrder = {
    "sharedPaymentUrl"
})
public class CreateAccessCodeSharedResponse2
    extends CreateAccessCodeResponse2
{

    @XmlElement(name = "SharedPaymentUrl")
    protected String sharedPaymentUrl;

    /**
     * Gets the value of the sharedPaymentUrl property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getSharedPaymentUrl() {
        return sharedPaymentUrl;
    }

    /**
     * Sets the value of the sharedPaymentUrl property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setSharedPaymentUrl(String value) {
        this.sharedPaymentUrl = value;
    }

}
