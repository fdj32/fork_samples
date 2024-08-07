
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for CardDetails complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="CardDetails"&gt;
 *   &lt;complexContent&gt;
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="Number" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="Name" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="ExpiryMonth" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="ExpiryYear" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="StartMonth" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="StartYear" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="IssueNumber" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CVN" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/restriction&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "CardDetails", propOrder = {
    "number",
    "name",
    "expiryMonth",
    "expiryYear",
    "startMonth",
    "startYear",
    "issueNumber",
    "cvn"
})
public class CardDetails {

    @XmlElement(name = "Number")
    protected String number;
    @XmlElement(name = "Name")
    protected String name;
    @XmlElement(name = "ExpiryMonth")
    protected String expiryMonth;
    @XmlElement(name = "ExpiryYear")
    protected String expiryYear;
    @XmlElement(name = "StartMonth")
    protected String startMonth;
    @XmlElement(name = "StartYear")
    protected String startYear;
    @XmlElement(name = "IssueNumber")
    protected String issueNumber;
    @XmlElement(name = "CVN")
    protected String cvn;

    /**
     * Gets the value of the number property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getNumber() {
        return number;
    }

    /**
     * Sets the value of the number property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setNumber(String value) {
        this.number = value;
    }

    /**
     * Gets the value of the name property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getName() {
        return name;
    }

    /**
     * Sets the value of the name property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setName(String value) {
        this.name = value;
    }

    /**
     * Gets the value of the expiryMonth property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getExpiryMonth() {
        return expiryMonth;
    }

    /**
     * Sets the value of the expiryMonth property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setExpiryMonth(String value) {
        this.expiryMonth = value;
    }

    /**
     * Gets the value of the expiryYear property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getExpiryYear() {
        return expiryYear;
    }

    /**
     * Sets the value of the expiryYear property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setExpiryYear(String value) {
        this.expiryYear = value;
    }

    /**
     * Gets the value of the startMonth property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getStartMonth() {
        return startMonth;
    }

    /**
     * Sets the value of the startMonth property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setStartMonth(String value) {
        this.startMonth = value;
    }

    /**
     * Gets the value of the startYear property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getStartYear() {
        return startYear;
    }

    /**
     * Sets the value of the startYear property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setStartYear(String value) {
        this.startYear = value;
    }

    /**
     * Gets the value of the issueNumber property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getIssueNumber() {
        return issueNumber;
    }

    /**
     * Sets the value of the issueNumber property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setIssueNumber(String value) {
        this.issueNumber = value;
    }

    /**
     * Gets the value of the cvn property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCVN() {
        return cvn;
    }

    /**
     * Sets the value of the cvn property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCVN(String value) {
        this.cvn = value;
    }

}
