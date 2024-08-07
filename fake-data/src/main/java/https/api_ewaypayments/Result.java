
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for Result complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="Result"&gt;
 *   &lt;complexContent&gt;
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="Id" type="{http://www.w3.org/2001/XMLSchema}int"/&gt;
 *         &lt;element name="ApiKey" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="PublicApiKey" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/restriction&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "Result", propOrder = {
    "id",
    "apiKey",
    "publicApiKey"
})
public class Result {

    @XmlElement(name = "Id")
    protected int id;
    @XmlElement(name = "ApiKey")
    protected String apiKey;
    @XmlElement(name = "PublicApiKey")
    protected String publicApiKey;

    /**
     * Gets the value of the id property.
     * 
     */
    public int getId() {
        return id;
    }

    /**
     * Sets the value of the id property.
     * 
     */
    public void setId(int value) {
        this.id = value;
    }

    /**
     * Gets the value of the apiKey property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getApiKey() {
        return apiKey;
    }

    /**
     * Sets the value of the apiKey property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setApiKey(String value) {
        this.apiKey = value;
    }

    /**
     * Gets the value of the publicApiKey property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getPublicApiKey() {
        return publicApiKey;
    }

    /**
     * Sets the value of the publicApiKey property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setPublicApiKey(String value) {
        this.publicApiKey = value;
    }

}
