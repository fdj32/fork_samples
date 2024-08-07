
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlSchemaType;
import javax.xml.bind.annotation.XmlType;
import javax.xml.datatype.XMLGregorianCalendar;


/**
 * <p>Java class for SettlementTransaction complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="SettlementTransaction"&gt;
 *   &lt;complexContent&gt;
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="SettlementID" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CurrencyCardTypeTransactionID" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="eWAYCustomerID" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="Currency" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="TransactionID" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="TxnReference" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CardType" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="Amount" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="TransactionType" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="TransactionDateTime" type="{http://www.w3.org/2001/XMLSchema}dateTime"/&gt;
 *         &lt;element name="SettlementDateTime" type="{http://www.w3.org/2001/XMLSchema}dateTime"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/restriction&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "SettlementTransaction", propOrder = {
    "settlementID",
    "currencyCardTypeTransactionID",
    "ewayCustomerID",
    "currency",
    "transactionID",
    "txnReference",
    "cardType",
    "amount",
    "transactionType",
    "transactionDateTime",
    "settlementDateTime"
})
public class SettlementTransaction {

    @XmlElement(name = "SettlementID")
    protected String settlementID;
    @XmlElement(name = "CurrencyCardTypeTransactionID")
    protected String currencyCardTypeTransactionID;
    @XmlElement(name = "eWAYCustomerID")
    protected int ewayCustomerID;
    @XmlElement(name = "Currency")
    protected String currency;
    @XmlElement(name = "TransactionID")
    protected int transactionID;
    @XmlElement(name = "TxnReference")
    protected String txnReference;
    @XmlElement(name = "CardType")
    protected String cardType;
    @XmlElement(name = "Amount")
    protected int amount;
    @XmlElement(name = "TransactionType")
    protected String transactionType;
    @XmlElement(name = "TransactionDateTime", required = true)
    @XmlSchemaType(name = "dateTime")
    protected XMLGregorianCalendar transactionDateTime;
    @XmlElement(name = "SettlementDateTime", required = true)
    @XmlSchemaType(name = "dateTime")
    protected XMLGregorianCalendar settlementDateTime;

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
     * Gets the value of the currencyCardTypeTransactionID property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCurrencyCardTypeTransactionID() {
        return currencyCardTypeTransactionID;
    }

    /**
     * Sets the value of the currencyCardTypeTransactionID property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCurrencyCardTypeTransactionID(String value) {
        this.currencyCardTypeTransactionID = value;
    }

    /**
     * Gets the value of the ewayCustomerID property.
     * 
     */
    public int getEWAYCustomerID() {
        return ewayCustomerID;
    }

    /**
     * Sets the value of the ewayCustomerID property.
     * 
     */
    public void setEWAYCustomerID(int value) {
        this.ewayCustomerID = value;
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
     * Gets the value of the transactionID property.
     * 
     */
    public int getTransactionID() {
        return transactionID;
    }

    /**
     * Sets the value of the transactionID property.
     * 
     */
    public void setTransactionID(int value) {
        this.transactionID = value;
    }

    /**
     * Gets the value of the txnReference property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getTxnReference() {
        return txnReference;
    }

    /**
     * Sets the value of the txnReference property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setTxnReference(String value) {
        this.txnReference = value;
    }

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
     * Gets the value of the amount property.
     * 
     */
    public int getAmount() {
        return amount;
    }

    /**
     * Sets the value of the amount property.
     * 
     */
    public void setAmount(int value) {
        this.amount = value;
    }

    /**
     * Gets the value of the transactionType property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getTransactionType() {
        return transactionType;
    }

    /**
     * Sets the value of the transactionType property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setTransactionType(String value) {
        this.transactionType = value;
    }

    /**
     * Gets the value of the transactionDateTime property.
     * 
     * @return
     *     possible object is
     *     {@link XMLGregorianCalendar }
     *     
     */
    public XMLGregorianCalendar getTransactionDateTime() {
        return transactionDateTime;
    }

    /**
     * Sets the value of the transactionDateTime property.
     * 
     * @param value
     *     allowed object is
     *     {@link XMLGregorianCalendar }
     *     
     */
    public void setTransactionDateTime(XMLGregorianCalendar value) {
        this.transactionDateTime = value;
    }

    /**
     * Gets the value of the settlementDateTime property.
     * 
     * @return
     *     possible object is
     *     {@link XMLGregorianCalendar }
     *     
     */
    public XMLGregorianCalendar getSettlementDateTime() {
        return settlementDateTime;
    }

    /**
     * Sets the value of the settlementDateTime property.
     * 
     * @param value
     *     allowed object is
     *     {@link XMLGregorianCalendar }
     *     
     */
    public void setSettlementDateTime(XMLGregorianCalendar value) {
        this.settlementDateTime = value;
    }

}
