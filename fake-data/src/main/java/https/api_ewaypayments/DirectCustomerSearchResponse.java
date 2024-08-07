
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
 *         &lt;element name="DirectCustomerSearchResult" type="{https://api.ewaypayments.com/}DirectCustomerSearchResponse" minOccurs="0"/&gt;
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
    "directCustomerSearchResult"
})
@XmlRootElement(name = "DirectCustomerSearchResponse")
public class DirectCustomerSearchResponse {

    @XmlElement(name = "DirectCustomerSearchResult")
    protected DirectCustomerSearchResponse2 directCustomerSearchResult;

    /**
     * Gets the value of the directCustomerSearchResult property.
     * 
     * @return
     *     possible object is
     *     {@link DirectCustomerSearchResponse2 }
     *     
     */
    public DirectCustomerSearchResponse2 getDirectCustomerSearchResult() {
        return directCustomerSearchResult;
    }

    /**
     * Sets the value of the directCustomerSearchResult property.
     * 
     * @param value
     *     allowed object is
     *     {@link DirectCustomerSearchResponse2 }
     *     
     */
    public void setDirectCustomerSearchResult(DirectCustomerSearchResponse2 value) {
        this.directCustomerSearchResult = value;
    }

}
