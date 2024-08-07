
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
 *         &lt;element name="APICredentialsResult" type="{https://api.ewaypayments.com/}APICredentialsResponse" minOccurs="0"/&gt;
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
    "apiCredentialsResult"
})
@XmlRootElement(name = "APICredentialsResponse")
public class APICredentialsResponse {

    @XmlElement(name = "APICredentialsResult")
    protected APICredentialsResponse2 apiCredentialsResult;

    /**
     * Gets the value of the apiCredentialsResult property.
     * 
     * @return
     *     possible object is
     *     {@link APICredentialsResponse2 }
     *     
     */
    public APICredentialsResponse2 getAPICredentialsResult() {
        return apiCredentialsResult;
    }

    /**
     * Sets the value of the apiCredentialsResult property.
     * 
     * @param value
     *     allowed object is
     *     {@link APICredentialsResponse2 }
     *     
     */
    public void setAPICredentialsResult(APICredentialsResponse2 value) {
        this.apiCredentialsResult = value;
    }

}
