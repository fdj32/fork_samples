
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for TransactionSearchResponse complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="TransactionSearchResponse"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}BaseResponse"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="Transactions" type="{https://api.ewaypayments.com/}ArrayOfTransactionResult" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "TransactionSearchResponse", propOrder = {
    "transactions"
})
public class TransactionSearchResponse2
    extends BaseResponse
{

    @XmlElement(name = "Transactions")
    protected ArrayOfTransactionResult transactions;

    /**
     * Gets the value of the transactions property.
     * 
     * @return
     *     possible object is
     *     {@link ArrayOfTransactionResult }
     *     
     */
    public ArrayOfTransactionResult getTransactions() {
        return transactions;
    }

    /**
     * Sets the value of the transactions property.
     * 
     * @param value
     *     allowed object is
     *     {@link ArrayOfTransactionResult }
     *     
     */
    public void setTransactions(ArrayOfTransactionResult value) {
        this.transactions = value;
    }

}
