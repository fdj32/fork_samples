
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
 *         &lt;element name="DirectAuthorisationResult" type="{https://api.ewaypayments.com/}DirectAuthorisationResponse" minOccurs="0"/&gt;
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
    "directAuthorisationResult"
})
@XmlRootElement(name = "DirectAuthorisationResponse")
public class DirectAuthorisationResponse {

    @XmlElement(name = "DirectAuthorisationResult")
    protected DirectAuthorisationResponse2 directAuthorisationResult;

    /**
     * Gets the value of the directAuthorisationResult property.
     * 
     * @return
     *     possible object is
     *     {@link DirectAuthorisationResponse2 }
     *     
     */
    public DirectAuthorisationResponse2 getDirectAuthorisationResult() {
        return directAuthorisationResult;
    }

    /**
     * Sets the value of the directAuthorisationResult property.
     * 
     * @param value
     *     allowed object is
     *     {@link DirectAuthorisationResponse2 }
     *     
     */
    public void setDirectAuthorisationResult(DirectAuthorisationResponse2 value) {
        this.directAuthorisationResult = value;
    }

}
