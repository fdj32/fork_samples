
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
 *         &lt;element name="APICodeLookupResult" type="{https://api.ewaypayments.com/}CodeLookupResponse" minOccurs="0"/&gt;
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
    "apiCodeLookupResult"
})
@XmlRootElement(name = "APICodeLookupResponse")
public class APICodeLookupResponse {

    @XmlElement(name = "APICodeLookupResult")
    protected CodeLookupResponse apiCodeLookupResult;

    /**
     * Gets the value of the apiCodeLookupResult property.
     * 
     * @return
     *     possible object is
     *     {@link CodeLookupResponse }
     *     
     */
    public CodeLookupResponse getAPICodeLookupResult() {
        return apiCodeLookupResult;
    }

    /**
     * Sets the value of the apiCodeLookupResult property.
     * 
     * @param value
     *     allowed object is
     *     {@link CodeLookupResponse }
     *     
     */
    public void setAPICodeLookupResult(CodeLookupResponse value) {
        this.apiCodeLookupResult = value;
    }

}
