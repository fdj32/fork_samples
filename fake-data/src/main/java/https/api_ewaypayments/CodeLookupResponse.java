
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for CodeLookupResponse complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="CodeLookupResponse"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}BaseResponse"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="Language" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CodeDetails" type="{https://api.ewaypayments.com/}ArrayOfErrorCodeDetails" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "CodeLookupResponse", propOrder = {
    "language",
    "codeDetails"
})
public class CodeLookupResponse
    extends BaseResponse
{

    @XmlElement(name = "Language")
    protected String language;
    @XmlElement(name = "CodeDetails")
    protected ArrayOfErrorCodeDetails codeDetails;

    /**
     * Gets the value of the language property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getLanguage() {
        return language;
    }

    /**
     * Sets the value of the language property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setLanguage(String value) {
        this.language = value;
    }

    /**
     * Gets the value of the codeDetails property.
     * 
     * @return
     *     possible object is
     *     {@link ArrayOfErrorCodeDetails }
     *     
     */
    public ArrayOfErrorCodeDetails getCodeDetails() {
        return codeDetails;
    }

    /**
     * Sets the value of the codeDetails property.
     * 
     * @param value
     *     allowed object is
     *     {@link ArrayOfErrorCodeDetails }
     *     
     */
    public void setCodeDetails(ArrayOfErrorCodeDetails value) {
        this.codeDetails = value;
    }

}
