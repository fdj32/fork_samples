
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
 *         &lt;element name="CreateAccessCodeResult" type="{https://api.ewaypayments.com/}CreateAccessCodeResponse" minOccurs="0"/&gt;
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
    "createAccessCodeResult"
})
@XmlRootElement(name = "CreateAccessCodeResponse")
public class CreateAccessCodeResponse {

    @XmlElement(name = "CreateAccessCodeResult")
    protected CreateAccessCodeResponse2 createAccessCodeResult;

    /**
     * Gets the value of the createAccessCodeResult property.
     * 
     * @return
     *     possible object is
     *     {@link CreateAccessCodeResponse2 }
     *     
     */
    public CreateAccessCodeResponse2 getCreateAccessCodeResult() {
        return createAccessCodeResult;
    }

    /**
     * Sets the value of the createAccessCodeResult property.
     * 
     * @param value
     *     allowed object is
     *     {@link CreateAccessCodeResponse2 }
     *     
     */
    public void setCreateAccessCodeResult(CreateAccessCodeResponse2 value) {
        this.createAccessCodeResult = value;
    }

}
