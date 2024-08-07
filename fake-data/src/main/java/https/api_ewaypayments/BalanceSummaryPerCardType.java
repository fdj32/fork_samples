
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for BalanceSummaryPerCardType complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="BalanceSummaryPerCardType"&gt;
 *   &lt;complexContent&gt;
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="CardType" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="NumberOfTransactions" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="Credit" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="Debit" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="Balance" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/restriction&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "BalanceSummaryPerCardType", propOrder = {
    "cardType",
    "numberOfTransactions",
    "credit",
    "debit",
    "balance"
})
public class BalanceSummaryPerCardType {

    @XmlElement(name = "CardType")
    protected String cardType;
    @XmlElement(name = "NumberOfTransactions")
    protected int numberOfTransactions;
    @XmlElement(name = "Credit")
    protected int credit;
    @XmlElement(name = "Debit")
    protected int debit;
    @XmlElement(name = "Balance")
    protected int balance;

    /**
     * Gets the value of the cardType property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCardType() {
        return cardType;
    }

    /**
     * Sets the value of the cardType property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCardType(String value) {
        this.cardType = value;
    }

    /**
     * Gets the value of the numberOfTransactions property.
     * 
     */
    public int getNumberOfTransactions() {
        return numberOfTransactions;
    }

    /**
     * Sets the value of the numberOfTransactions property.
     * 
     */
    public void setNumberOfTransactions(int value) {
        this.numberOfTransactions = value;
    }

    /**
     * Gets the value of the credit property.
     * 
     */
    public int getCredit() {
        return credit;
    }

    /**
     * Sets the value of the credit property.
     * 
     */
    public void setCredit(int value) {
        this.credit = value;
    }

    /**
     * Gets the value of the debit property.
     * 
     */
    public int getDebit() {
        return debit;
    }

    /**
     * Sets the value of the debit property.
     * 
     */
    public void setDebit(int value) {
        this.debit = value;
    }

    /**
     * Gets the value of the balance property.
     * 
     */
    public int getBalance() {
        return balance;
    }

    /**
     * Sets the value of the balance property.
     * 
     */
    public void setBalance(int value) {
        this.balance = value;
    }

}
