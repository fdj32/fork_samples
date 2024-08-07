
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for SettlementReportResponse complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="SettlementReportResponse"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}BaseResponse"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="SettlementSummaries" type="{https://api.ewaypayments.com/}ArrayOfSettlementSummary" minOccurs="0"/&gt;
 *         &lt;element name="SettlementTransactions" type="{https://api.ewaypayments.com/}ArrayOfSettlementTransaction" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "SettlementReportResponse", propOrder = {
    "settlementSummaries",
    "settlementTransactions"
})
public class SettlementReportResponse
    extends BaseResponse
{

    @XmlElement(name = "SettlementSummaries")
    protected ArrayOfSettlementSummary settlementSummaries;
    @XmlElement(name = "SettlementTransactions")
    protected ArrayOfSettlementTransaction settlementTransactions;

    /**
     * Gets the value of the settlementSummaries property.
     * 
     * @return
     *     possible object is
     *     {@link ArrayOfSettlementSummary }
     *     
     */
    public ArrayOfSettlementSummary getSettlementSummaries() {
        return settlementSummaries;
    }

    /**
     * Sets the value of the settlementSummaries property.
     * 
     * @param value
     *     allowed object is
     *     {@link ArrayOfSettlementSummary }
     *     
     */
    public void setSettlementSummaries(ArrayOfSettlementSummary value) {
        this.settlementSummaries = value;
    }

    /**
     * Gets the value of the settlementTransactions property.
     * 
     * @return
     *     possible object is
     *     {@link ArrayOfSettlementTransaction }
     *     
     */
    public ArrayOfSettlementTransaction getSettlementTransactions() {
        return settlementTransactions;
    }

    /**
     * Sets the value of the settlementTransactions property.
     * 
     * @param value
     *     allowed object is
     *     {@link ArrayOfSettlementTransaction }
     *     
     */
    public void setSettlementTransactions(ArrayOfSettlementTransaction value) {
        this.settlementTransactions = value;
    }

}
