
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
 *         &lt;element name="CreateAccessCodeSharedResult" type="{https://api.ewaypayments.com/}CreateAccessCodeSharedResponse" minOccurs="0"/&gt;
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
    "createAccessCodeSharedResult"
})
@XmlRootElement(name = "CreateAccessCodeSharedResponse")
public class CreateAccessCodeSharedResponse {

    @XmlElement(name = "CreateAccessCodeSharedResult")
    protected CreateAccessCodeSharedResponse2 createAccessCodeSharedResult;

    /**
     * Gets the value of the createAccessCodeSharedResult property.
     * 
     * @return
     *     possible object is
     *     {@link CreateAccessCodeSharedResponse2 }
     *     
     */
    public CreateAccessCodeSharedResponse2 getCreateAccessCodeSharedResult() {
        return createAccessCodeSharedResult;
    }

    /**
     * Sets the value of the createAccessCodeSharedResult property.
     * 
     * @param value
     *     allowed object is
     *     {@link CreateAccessCodeSharedResponse2 }
     *     
     */
    public void setCreateAccessCodeSharedResult(CreateAccessCodeSharedResponse2 value) {
        this.createAccessCodeSharedResult = value;
    }

}
