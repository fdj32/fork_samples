
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for anonymous complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType&gt;
 *   &lt;complexContent&gt;
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="SettlementSearchResult" type="{https://api.ewaypayments.com/}SettlementReportResponse" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/restriction&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "", propOrder = {
    "settlementSearchResult"
})
@XmlRootElement(name = "SettlementSearchResponse")
public class SettlementSearchResponse {

    @XmlElement(name = "SettlementSearchResult")
    protected SettlementReportResponse settlementSearchResult;

    /**
     * Gets the value of the settlementSearchResult property.
     * 
     * @return
     *     possible object is
     *     {@link SettlementReportResponse }
     *     
     */
    public SettlementReportResponse getSettlementSearchResult() {
        return settlementSearchResult;
    }

    /**
     * Sets the value of the settlementSearchResult property.
     * 
     * @param value
     *     allowed object is
     *     {@link SettlementReportResponse }
     *     
     */
    public void setSettlementSearchResult(SettlementReportResponse value) {
        this.settlementSearchResult = value;
    }

}
