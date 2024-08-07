
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for SettlementSummary complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="SettlementSummary"&gt;
 *   &lt;complexContent&gt;
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="SettlementID" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="Currency" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="TotalCredit" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="TotalDebit" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="TotalBalance" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="BalancePerCardType" type="{https://api.ewaypayments.com/}ArrayOfBalanceSummaryPerCardType" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/restriction&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "SettlementSummary", propOrder = {
    "settlementID",
    "currency",
    "totalCredit",
    "totalDebit",
    "totalBalance",
    "balancePerCardType"
})
public class SettlementSummary {

    @XmlElement(name = "SettlementID")
    protected String settlementID;
    @XmlElement(name = "Currency")
    protected String currency;
    @XmlElement(name = "TotalCredit")
    protected int totalCredit;
    @XmlElement(name = "TotalDebit")
    protected int totalDebit;
    @XmlElement(name = "TotalBalance")
    protected int totalBalance;
    @XmlElement(name = "BalancePerCardType")
    protected ArrayOfBalanceSummaryPerCardType balancePerCardType;

    /**
     * Gets the value of the settlementID property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getSettlementID() {
        return settlementID;
    }

    /**
     * Sets the value of the settlementID property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setSettlementID(String value) {
        this.settlementID = value;
    }

    /**
     * Gets the value of the currency property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCurrency() {
        return currency;
    }

    /**
     * Sets the value of the currency property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCurrency(String value) {
        this.currency = value;
    }

    /**
     * Gets the value of the totalCredit property.
     * 
     */
    public int getTotalCredit() {
        return totalCredit;
    }

    /**
     * Sets the value of the totalCredit property.
     * 
     */
    public void setTotalCredit(int value) {
        this.totalCredit = value;
    }

    /**
     * Gets the value of the totalDebit property.
     * 
     */
    public int getTotalDebit() {
        return totalDebit;
    }

    /**
     * Sets the value of the totalDebit property.
     * 
     */
    public void setTotalDebit(int value) {
        this.totalDebit = value;
    }

    /**
     * Gets the value of the totalBalance property.
     * 
     */
    public int getTotalBalance() {
        return totalBalance;
    }

    /**
     * Sets the value of the totalBalance property.
     * 
     */
    public void setTotalBalance(int value) {
        this.totalBalance = value;
    }

    /**
     * Gets the value of the balancePerCardType property.
     * 
     * @return
     *     possible object is
     *     {@link ArrayOfBalanceSummaryPerCardType }
     *     
     */
    public ArrayOfBalanceSummaryPerCardType getBalancePerCardType() {
        return balancePerCardType;
    }

    /**
     * Sets the value of the balancePerCardType property.
     * 
     * @param value
     *     allowed object is
     *     {@link ArrayOfBalanceSummaryPerCardType }
     *     
     */
    public void setBalancePerCardType(ArrayOfBalanceSummaryPerCardType value) {
        this.balancePerCardType = value;
    }

}
