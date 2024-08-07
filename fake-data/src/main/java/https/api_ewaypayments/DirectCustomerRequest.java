
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for DirectCustomerRequest complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="DirectCustomerRequest"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}BaseRequest"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="Customer" type="{https://api.ewaypayments.com/}DirectTokenCustomer" minOccurs="0"/&gt;
 *         &lt;element name="ThirdPartyWalletID" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="SecuredCardData" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "DirectCustomerRequest", propOrder = {
    "customer",
    "thirdPartyWalletID",
    "securedCardData"
})
public class DirectCustomerRequest
    extends BaseRequest
{

    @XmlElement(name = "Customer")
    protected DirectTokenCustomer customer;
    @XmlElement(name = "ThirdPartyWalletID")
    protected String thirdPartyWalletID;
    @XmlElement(name = "SecuredCardData")
    protected String securedCardData;

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

    /**
     * Gets the value of the thirdPartyWalletID property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getThirdPartyWalletID() {
        return thirdPartyWalletID;
    }

    /**
     * Sets the value of the thirdPartyWalletID property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setThirdPartyWalletID(String value) {
        this.thirdPartyWalletID = value;
    }

    /**
     * Gets the value of the securedCardData property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getSecuredCardData() {
        return securedCardData;
    }

    /**
     * Sets the value of the securedCardData property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setSecuredCardData(String value) {
        this.securedCardData = value;
    }

}
