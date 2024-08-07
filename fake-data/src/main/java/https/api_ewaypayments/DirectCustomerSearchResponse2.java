
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for DirectCustomerSearchResponse complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="DirectCustomerSearchResponse"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}BaseResponse"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="Customers" type="{https://api.ewaypayments.com/}ArrayOfDirectTokenCustomer" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "DirectCustomerSearchResponse", propOrder = {
    "customers"
})
public class DirectCustomerSearchResponse2
    extends BaseResponse
{

    @XmlElement(name = "Customers")
    protected ArrayOfDirectTokenCustomer customers;

    /**
     * Gets the value of the customers property.
     * 
     * @return
     *     possible object is
     *     {@link ArrayOfDirectTokenCustomer }
     *     
     */
    public ArrayOfDirectTokenCustomer getCustomers() {
        return customers;
    }

    /**
     * Sets the value of the customers property.
     * 
     * @param value
     *     allowed object is
     *     {@link ArrayOfDirectTokenCustomer }
     *     
     */
    public void setCustomers(ArrayOfDirectTokenCustomer value) {
        this.customers = value;
    }

}
