
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for TransactionSearchRequest complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="TransactionSearchRequest"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}BaseRequest"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="TransactionFilter" type="{https://api.ewaypayments.com/}TransactionFilter" minOccurs="0"/&gt;
 *         &lt;element name="PageSize" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="PageNumber" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "TransactionSearchRequest", propOrder = {
    "transactionFilter",
    "pageSize",
    "pageNumber"
})
public class TransactionSearchRequest
    extends BaseRequest
{

    @XmlElement(name = "TransactionFilter")
    protected TransactionFilter transactionFilter;
    @XmlElement(name = "PageSize")
    protected int pageSize;
    @XmlElement(name = "PageNumber")
    protected int pageNumber;

    /**
     * Gets the value of the transactionFilter property.
     * 
     * @return
     *     possible object is
     *     {@link TransactionFilter }
     *     
     */
    public TransactionFilter getTransactionFilter() {
        return transactionFilter;
    }

    /**
     * Sets the value of the transactionFilter property.
     * 
     * @param value
     *     allowed object is
     *     {@link TransactionFilter }
     *     
     */
    public void setTransactionFilter(TransactionFilter value) {
        this.transactionFilter = value;
    }

    /**
     * Gets the value of the pageSize property.
     * 
     */
    public int getPageSize() {
        return pageSize;
    }

    /**
     * Sets the value of the pageSize property.
     * 
     */
    public void setPageSize(int value) {
        this.pageSize = value;
    }

    /**
     * Gets the value of the pageNumber property.
     * 
     */
    public int getPageNumber() {
        return pageNumber;
    }

    /**
     * Sets the value of the pageNumber property.
     * 
     */
    public void setPageNumber(int value) {
        this.pageNumber = value;
    }

}
