
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlSchemaType;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for CustomerFilter complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="CustomerFilter"&gt;
 *   &lt;complexContent&gt;
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="TokenCustomerIDMatchType" type="{https://api.ewaypayments.com/}FilterMatchType"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/restriction&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "CustomerFilter", propOrder = {
    "tokenCustomerIDMatchType"
})
public class CustomerFilter {

    @XmlElement(name = "TokenCustomerIDMatchType", required = true)
    @XmlSchemaType(name = "string")
    protected FilterMatchType tokenCustomerIDMatchType;

    /**
     * Gets the value of the tokenCustomerIDMatchType property.
     * 
     * @return
     *     possible object is
     *     {@link FilterMatchType }
     *     
     */
    public FilterMatchType getTokenCustomerIDMatchType() {
        return tokenCustomerIDMatchType;
    }

    /**
     * Sets the value of the tokenCustomerIDMatchType property.
     * 
     * @param value
     *     allowed object is
     *     {@link FilterMatchType }
     *     
     */
    public void setTokenCustomerIDMatchType(FilterMatchType value) {
        this.tokenCustomerIDMatchType = value;
    }

}
