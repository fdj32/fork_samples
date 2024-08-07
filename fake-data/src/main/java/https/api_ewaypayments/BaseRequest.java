
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlSeeAlso;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for BaseRequest complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="BaseRequest"&gt;
 *   &lt;complexContent&gt;
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType"&gt;
 *     &lt;/restriction&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "BaseRequest")
@XmlSeeAlso({
    CreateAccessCodeRequest.class,
    GetAccessCodeResultRequest.class,
    DirectPaymentRequest.class,
    DirectCustomerRequest.class,
    DirectRefundRequest.class,
    DirectCustomerSearchRequest.class,
    TransactionSearchRequest.class,
    SettlementReportRequest.class,
    CodeLookupRequest.class,
    APICredentialsRequest.class,
    CaptureAuthBaseRequest.class
})
public class BaseRequest {


}
