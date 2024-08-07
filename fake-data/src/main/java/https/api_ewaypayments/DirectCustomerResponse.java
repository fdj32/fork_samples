
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for DirectCustomerResponse complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="DirectCustomerResponse"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}BaseResponse"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="Customer" type="{https://api.ewaypayments.com/}DirectTokenCustomer" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "DirectCustomerResponse", propOrder = {
    "customer"
})
public class DirectCustomerResponse
    extends BaseResponse
{

    @XmlElement(name = "Customer")
    protected DirectTokenCustomer customer;

    /**
     * Gets the value of the customer property.
     * 
     * @return
     *     possible object is
     *     {@link DirectTokenCustomer }
     *     
     */
    public DirectTokenCustomer getCustomer() {
        return customer;
    }

    /**
     * Sets the value of the customer property.
     * 
     * @param value
     *     allowed object is
     *     {@link DirectTokenCustomer }
     *     
     */
    public void setCustomer(DirectTokenCustomer value) {
        this.customer = value;
    }

}
