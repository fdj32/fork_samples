
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for GetAccessCodeResultRequest complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="GetAccessCodeResultRequest"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}BaseRequest"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="AccessCode" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "GetAccessCodeResultRequest", propOrder = {
    "accessCode"
})
public class GetAccessCodeResultRequest
    extends BaseRequest
{

    @XmlElement(name = "AccessCode")
    protected String accessCode;

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

}
