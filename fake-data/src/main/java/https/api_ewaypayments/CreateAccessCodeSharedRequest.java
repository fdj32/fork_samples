
package https.api_ewaypayments;

import java.util.ArrayList;
import java.util.List;
import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlList;
import javax.xml.bind.annotation.XmlSchemaType;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for CreateAccessCodeSharedRequest complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="CreateAccessCodeSharedRequest"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}CreateAccessCodeRequest"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="CustomerReadOnly" type="{http://www.w3.org/2001/XMLSchema}boolean"/&gt;
 *         &lt;element name="VerifyCustomerPhone" type="{http://www.w3.org/2001/XMLSchema}boolean"/&gt;
 *         &lt;element name="VerifyCustomerEmail" type="{http://www.w3.org/2001/XMLSchema}boolean"/&gt;
 *         &lt;element name="ReturnUrl" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="LogoUrl" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="FooterText" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="HeaderText" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="Language" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="AllowedCards" type="{https://api.ewaypayments.com/}AllowedCards" minOccurs="0"/&gt;
 *         &lt;element name="CustomView" type="{https://api.ewaypayments.com/}CustomView"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "CreateAccessCodeSharedRequest", propOrder = {
    "customerReadOnly",
    "verifyCustomerPhone",
    "verifyCustomerEmail",
    "returnUrl",
    "logoUrl",
    "footerText",
    "headerText",
    "language",
    "allowedCards",
    "customView"
})
public class CreateAccessCodeSharedRequest
    extends CreateAccessCodeRequest
{

    @XmlElement(name = "CustomerReadOnly", required = true, type = Boolean.class, nillable = true)
    protected Boolean customerReadOnly;
    @XmlElement(name = "VerifyCustomerPhone", required = true, type = Boolean.class, nillable = true)
    protected Boolean verifyCustomerPhone;
    @XmlElement(name = "VerifyCustomerEmail", required = true, type = Boolean.class, nillable = true)
    protected Boolean verifyCustomerEmail;
    @XmlElement(name = "ReturnUrl")
    protected String returnUrl;
    @XmlElement(name = "LogoUrl")
    protected String logoUrl;
    @XmlElement(name = "FooterText")
    protected String footerText;
    @XmlElement(name = "HeaderText")
    protected String headerText;
    @XmlElement(name = "Language")
    protected String language;
    @XmlList
    @XmlElement(name = "AllowedCards", defaultValue = "None")
    protected List<String> allowedCards;
    @XmlElement(name = "CustomView", required = true, nillable = true)
    @XmlSchemaType(name = "string")
    protected CustomView customView;

    /**
     * Gets the value of the customerReadOnly property.
     * 
     * @return
     *     possible object is
     *     {@link Boolean }
     *     
     */
    public Boolean isCustomerReadOnly() {
        return customerReadOnly;
    }

    /**
     * Sets the value of the customerReadOnly property.
     * 
     * @param value
     *     allowed object is
     *     {@link Boolean }
     *     
     */
    public void setCustomerReadOnly(Boolean value) {
        this.customerReadOnly = value;
    }

    /**
     * Gets the value of the verifyCustomerPhone property.
     * 
     * @return
     *     possible object is
     *     {@link Boolean }
     *     
     */
    public Boolean isVerifyCustomerPhone() {
        return verifyCustomerPhone;
    }

    /**
     * Sets the value of the verifyCustomerPhone property.
     * 
     * @param value
     *     allowed object is
     *     {@link Boolean }
     *     
     */
    public void setVerifyCustomerPhone(Boolean value) {
        this.verifyCustomerPhone = value;
    }

    /**
     * Gets the value of the verifyCustomerEmail property.
     * 
     * @return
     *     possible object is
     *     {@link Boolean }
     *     
     */
    public Boolean isVerifyCustomerEmail() {
        return verifyCustomerEmail;
    }

    /**
     * Sets the value of the verifyCustomerEmail property.
     * 
     * @param value
     *     allowed object is
     *     {@link Boolean }
     *     
     */
    public void setVerifyCustomerEmail(Boolean value) {
        this.verifyCustomerEmail = value;
    }

    /**
     * Gets the value of the returnUrl property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getReturnUrl() {
        return returnUrl;
    }

    /**
     * Sets the value of the returnUrl property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setReturnUrl(String value) {
        this.returnUrl = value;
    }

    /**
     * Gets the value of the logoUrl property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getLogoUrl() {
        return logoUrl;
    }

    /**
     * Sets the value of the logoUrl property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setLogoUrl(String value) {
        this.logoUrl = value;
    }

    /**
     * Gets the value of the footerText property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getFooterText() {
        return footerText;
    }

    /**
     * Sets the value of the footerText property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setFooterText(String value) {
        this.footerText = value;
    }

    /**
     * Gets the value of the headerText property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getHeaderText() {
        return headerText;
    }

    /**
     * Sets the value of the headerText property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setHeaderText(String value) {
        this.headerText = value;
    }

    /**
     * Gets the value of the language property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getLanguage() {
        return language;
    }

    /**
     * Sets the value of the language property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setLanguage(String value) {
        this.language = value;
    }

    /**
     * Gets the value of the allowedCards property.
     * 
     * <p>
     * This accessor method returns a reference to the live list,
     * not a snapshot. Therefore any modification you make to the
     * returned list will be present inside the JAXB object.
     * This is why there is not a <CODE>set</CODE> method for the allowedCards property.
     * 
     * <p>
     * For example, to add a new item, do as follows:
     * <pre>
     *    getAllowedCards().add(newItem);
     * </pre>
     * 
     * 
     * <p>
     * Objects of the following type(s) are allowed in the list
     * {@link String }
     * 
     * 
     */
    public List<String> getAllowedCards() {
        if (allowedCards == null) {
            allowedCards = new ArrayList<String>();
        }
        return this.allowedCards;
    }

    /**
     * Gets the value of the customView property.
     * 
     * @return
     *     possible object is
     *     {@link CustomView }
     *     
     */
    public CustomView getCustomView() {
        return customView;
    }

    /**
     * Sets the value of the customView property.
     * 
     * @param value
     *     allowed object is
     *     {@link CustomView }
     *     
     */
    public void setCustomView(CustomView value) {
        this.customView = value;
    }

}
