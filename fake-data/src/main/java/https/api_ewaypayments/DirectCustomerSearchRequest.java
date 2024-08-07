
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for DirectCustomerSearchRequest complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="DirectCustomerSearchRequest"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}BaseRequest"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="CustomerFilter" type="{https://api.ewaypayments.com/}CustomerFilter" minOccurs="0"/&gt;
 *         &lt;element name="TokenCustomerID" type="{http://www.w3.org/2001/XMLSchema}long"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "DirectCustomerSearchRequest", propOrder = {
    "customerFilter",
    "tokenCustomerID"
})
public class DirectCustomerSearchRequest
    extends BaseRequest
{

    @XmlElement(name = "CustomerFilter")
    protected CustomerFilter customerFilter;
    @XmlElement(name = "TokenCustomerID")
    protected long tokenCustomerID;

    /**
     * Gets the value of the customerFilter property.
     * 
     * @return
     *     possible object is
     *     {@link CustomerFilter }
     *     
     */
    public CustomerFilter getCustomerFilter() {
        return customerFilter;
    }

    /**
     * Sets the value of the customerFilter property.
     * 
     * @param value
     *     allowed object is
     *     {@link CustomerFilter }
     *     
     */
    public void setCustomerFilter(CustomerFilter value) {
        this.customerFilter = value;
    }

    /**
     * Gets the value of the tokenCustomerID property.
     * 
     */
    public long getTokenCustomerID() {
        return tokenCustomerID;
    }

    /**
     * Sets the value of the tokenCustomerID property.
     * 
     */
    public void setTokenCustomerID(long value) {
        this.tokenCustomerID = value;
    }

}
