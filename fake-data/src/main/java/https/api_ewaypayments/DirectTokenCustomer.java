
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for DirectTokenCustomer complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="DirectTokenCustomer"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}TokenCustomer"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="CardDetails" type="{https://api.ewaypayments.com/}CardDetails" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "DirectTokenCustomer", propOrder = {
    "cardDetails"
})
public class DirectTokenCustomer
    extends TokenCustomer
{

    @XmlElement(name = "CardDetails")
    protected CardDetails cardDetails;

    /**
     * Gets the value of the cardDetails property.
     * 
     * @return
     *     possible object is
     *     {@link CardDetails }
     *     
     */
    public CardDetails getCardDetails() {
        return cardDetails;
    }

    /**
     * Sets the value of the cardDetails property.
     * 
     * @param value
     *     allowed object is
     *     {@link CardDetails }
     *     
     */
    public void setCardDetails(CardDetails value) {
        this.cardDetails = value;
    }

}
