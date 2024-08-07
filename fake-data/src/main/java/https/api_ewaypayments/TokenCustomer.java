
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlSeeAlso;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for TokenCustomer complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="TokenCustomer"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}Customer"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="CardNumber" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CardStartMonth" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CardStartYear" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CardIssueNumber" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CardName" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CardExpiryMonth" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CardExpiryYear" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="IsActive" type="{http://www.w3.org/2001/XMLSchema}boolean" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "TokenCustomer", propOrder = {
    "cardNumber",
    "cardStartMonth",
    "cardStartYear",
    "cardIssueNumber",
    "cardName",
    "cardExpiryMonth",
    "cardExpiryYear",
    "isActive"
})
@XmlSeeAlso({
    DirectTokenCustomer.class
})
public class TokenCustomer
    extends Customer
{

    @XmlElement(name = "CardNumber")
    protected String cardNumber;
    @XmlElement(name = "CardStartMonth")
    protected String cardStartMonth;
    @XmlElement(name = "CardStartYear")
    protected String cardStartYear;
    @XmlElement(name = "CardIssueNumber")
    protected String cardIssueNumber;
    @XmlElement(name = "CardName")
    protected String cardName;
    @XmlElement(name = "CardExpiryMonth")
    protected String cardExpiryMonth;
    @XmlElement(name = "CardExpiryYear")
    protected String cardExpiryYear;
    @XmlElement(name = "IsActive")
    protected Boolean isActive;

    /**
     * Gets the value of the cardNumber property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCardNumber() {
        return cardNumber;
    }

    /**
     * Sets the value of the cardNumber property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCardNumber(String value) {
        this.cardNumber = value;
    }

    /**
     * Gets the value of the cardStartMonth property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCardStartMonth() {
        return cardStartMonth;
    }

    /**
     * Sets the value of the cardStartMonth property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCardStartMonth(String value) {
        this.cardStartMonth = value;
    }

    /**
     * Gets the value of the cardStartYear property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCardStartYear() {
        return cardStartYear;
    }

    /**
     * Sets the value of the cardStartYear property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCardStartYear(String value) {
        this.cardStartYear = value;
    }

    /**
     * Gets the value of the cardIssueNumber property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCardIssueNumber() {
        return cardIssueNumber;
    }

    /**
     * Sets the value of the cardIssueNumber property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCardIssueNumber(String value) {
        this.cardIssueNumber = value;
    }

    /**
     * Gets the value of the cardName property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCardName() {
        return cardName;
    }

    /**
     * Sets the value of the cardName property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCardName(String value) {
        this.cardName = value;
    }

    /**
     * Gets the value of the cardExpiryMonth property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCardExpiryMonth() {
        return cardExpiryMonth;
    }

    /**
     * Sets the value of the cardExpiryMonth property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCardExpiryMonth(String value) {
        this.cardExpiryMonth = value;
    }

    /**
     * Gets the value of the cardExpiryYear property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCardExpiryYear() {
        return cardExpiryYear;
    }

    /**
     * Sets the value of the cardExpiryYear property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCardExpiryYear(String value) {
        this.cardExpiryYear = value;
    }

    /**
     * Gets the value of the isActive property.
     * 
     * @return
     *     possible object is
     *     {@link Boolean }
     *     
     */
    public Boolean isIsActive() {
        return isActive;
    }

    /**
     * Sets the value of the isActive property.
     * 
     * @param value
     *     allowed object is
     *     {@link Boolean }
     *     
     */
    public void setIsActive(Boolean value) {
        this.isActive = value;
    }

}
