
package https.api_ewaypayments;

import java.util.ArrayList;
import java.util.List;
import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for ArrayOfErrorCodeDetails complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="ArrayOfErrorCodeDetails"&gt;
 *   &lt;complexContent&gt;
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="ErrorCodeDetails" type="{https://api.ewaypayments.com/}ErrorCodeDetails" maxOccurs="unbounded" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/restriction&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "ArrayOfErrorCodeDetails", propOrder = {
    "errorCodeDetails"
})
public class ArrayOfErrorCodeDetails {

    @XmlElement(name = "ErrorCodeDetails", nillable = true)
    protected List<ErrorCodeDetails> errorCodeDetails;

    /**
     * Gets the value of the errorCodeDetails property.
     * 
     * <p>
     * This accessor method returns a reference to the live list,
     * not a snapshot. Therefore any modification you make to the
     * returned list will be present inside the JAXB object.
     * This is why there is not a <CODE>set</CODE> method for the errorCodeDetails property.
     * 
     * <p>
     * For example, to add a new item, do as follows:
     * <pre>
     *    getErrorCodeDetails().add(newItem);
     * </pre>
     * 
     * 
     * <p>
     * Objects of the following type(s) are allowed in the list
     * {@link ErrorCodeDetails }
     * 
     * 
     */
    public List<ErrorCodeDetails> getErrorCodeDetails() {
        if (errorCodeDetails == null) {
            errorCodeDetails = new ArrayList<ErrorCodeDetails>();
        }
        return this.errorCodeDetails;
    }

}
