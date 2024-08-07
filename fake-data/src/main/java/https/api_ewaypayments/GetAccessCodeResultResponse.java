
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
 *         &lt;element name="GetAccessCodeResultResult" type="{https://api.ewaypayments.com/}GetAccessCodeResultResponse" minOccurs="0"/&gt;
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
    "getAccessCodeResultResult"
})
@XmlRootElement(name = "GetAccessCodeResultResponse")
public class GetAccessCodeResultResponse {

    @XmlElement(name = "GetAccessCodeResultResult")
    protected GetAccessCodeResultResponse2 getAccessCodeResultResult;

    /**
     * Gets the value of the getAccessCodeResultResult property.
     * 
     * @return
     *     possible object is
     *     {@link GetAccessCodeResultResponse2 }
     *     
     */
    public GetAccessCodeResultResponse2 getGetAccessCodeResultResult() {
        return getAccessCodeResultResult;
    }

    /**
     * Sets the value of the getAccessCodeResultResult property.
     * 
     * @param value
     *     allowed object is
     *     {@link GetAccessCodeResultResponse2 }
     *     
     */
    public void setGetAccessCodeResultResult(GetAccessCodeResultResponse2 value) {
        this.getAccessCodeResultResult = value;
    }

}
