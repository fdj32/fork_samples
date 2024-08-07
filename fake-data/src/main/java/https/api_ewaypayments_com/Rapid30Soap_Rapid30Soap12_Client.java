
package https.api_ewaypayments_com;

/**
 * Please modify this class to meet your needs
 * This class is not complete
 */

import java.io.File;
import java.net.MalformedURLException;
import java.net.URL;
import javax.xml.namespace.QName;
import javax.jws.WebMethod;
import javax.jws.WebParam;
import javax.jws.WebResult;
import javax.jws.WebService;
import javax.xml.bind.annotation.XmlSeeAlso;
import javax.xml.ws.RequestWrapper;
import javax.xml.ws.ResponseWrapper;

/**
 * This class was generated by Apache CXF 3.5.9
 * 2024-08-06T16:29:11.271+08:00
 * Generated source version: 3.5.9
 *
 */
public final class Rapid30Soap_Rapid30Soap12_Client {
	
    private static final QName SERVICE_NAME = new QName("https://api.ewaypayments.com/", "Rapid3.0");

    private Rapid30Soap_Rapid30Soap12_Client() {
    }

    public static void main(String args[]) throws java.lang.Exception {
        URL wsdlURL = Rapid30.WSDL_LOCATION;
        if (args.length > 0 && args[0] != null && !"".equals(args[0])) {
            File wsdlFile = new File(args[0]);
            try {
                if (wsdlFile.exists()) {
                    wsdlURL = wsdlFile.toURI().toURL();
                } else {
                    wsdlURL = new URL(args[0]);
                }
            } catch (MalformedURLException e) {
                e.printStackTrace();
            }
        }

        Rapid30 ss = new Rapid30(wsdlURL, SERVICE_NAME);
        Rapid30Soap port = ss.getRapid30Soap12();

        {
        System.out.println("Invoking directCustomerUpdate...");
        https.api_ewaypayments.DirectCustomerRequest _directCustomerUpdate_request = null;
        https.api_ewaypayments.DirectCustomerResponse _directCustomerUpdate__return = port.directCustomerUpdate(_directCustomerUpdate_request);
        System.out.println("directCustomerUpdate.result=" + _directCustomerUpdate__return);


        }
        {
        System.out.println("Invoking cancelAuthorisation...");
        https.api_ewaypayments.CancelAuthorisationRequest _cancelAuthorisation_request = null;
        https.api_ewaypayments.CancelAuthorisationResponse2 _cancelAuthorisation__return = port.cancelAuthorisation(_cancelAuthorisation_request);
        System.out.println("cancelAuthorisation.result=" + _cancelAuthorisation__return);


        }
        {
        System.out.println("Invoking createAccessCode...");
        https.api_ewaypayments.CreateAccessCodeRequest _createAccessCode_request = null;
        https.api_ewaypayments.CreateAccessCodeResponse2 _createAccessCode__return = port.createAccessCode(_createAccessCode_request);
        System.out.println("createAccessCode.result=" + _createAccessCode__return);


        }
        {
        System.out.println("Invoking createAccessCodeShared...");
        https.api_ewaypayments.CreateAccessCodeSharedRequest _createAccessCodeShared_request = null;
        https.api_ewaypayments.CreateAccessCodeSharedResponse2 _createAccessCodeShared__return = port.createAccessCodeShared(_createAccessCodeShared_request);
        System.out.println("createAccessCodeShared.result=" + _createAccessCodeShared__return);


        }
        {
        System.out.println("Invoking directPayment...");
        https.api_ewaypayments.DirectPaymentRequest _directPayment_request = null;
        https.api_ewaypayments.DirectPaymentResponse2 _directPayment__return = port.directPayment(_directPayment_request);
        System.out.println("directPayment.result=" + _directPayment__return);


        }
        {
        System.out.println("Invoking directCustomerCreate...");
        https.api_ewaypayments.DirectCustomerRequest _directCustomerCreate_request = null;
        https.api_ewaypayments.DirectCustomerResponse _directCustomerCreate__return = port.directCustomerCreate(_directCustomerCreate_request);
        System.out.println("directCustomerCreate.result=" + _directCustomerCreate__return);


        }
        {
        System.out.println("Invoking directCustomerSearch...");
        https.api_ewaypayments.DirectCustomerSearchRequest _directCustomerSearch_request = null;
        https.api_ewaypayments.DirectCustomerSearchResponse2 _directCustomerSearch__return = port.directCustomerSearch(_directCustomerSearch_request);
        System.out.println("directCustomerSearch.result=" + _directCustomerSearch__return);


        }
        {
        System.out.println("Invoking settlementSearch...");
        https.api_ewaypayments.SettlementReportRequest _settlementSearch_request = null;
        https.api_ewaypayments.SettlementReportResponse _settlementSearch__return = port.settlementSearch(_settlementSearch_request);
        System.out.println("settlementSearch.result=" + _settlementSearch__return);


        }
        {
        System.out.println("Invoking apiCredentials...");
        https.api_ewaypayments.APICredentialsRequest _apiCredentials_request = null;
        https.api_ewaypayments.APICredentialsResponse2 _apiCredentials__return = port.apiCredentials(_apiCredentials_request);
        System.out.println("apiCredentials.result=" + _apiCredentials__return);


        }
        {
        System.out.println("Invoking directAuthorisation...");
        https.api_ewaypayments.DirectAuthorisationRequest _directAuthorisation_request = null;
        https.api_ewaypayments.DirectAuthorisationResponse2 _directAuthorisation__return = port.directAuthorisation(_directAuthorisation_request);
        System.out.println("directAuthorisation.result=" + _directAuthorisation__return);


        }
        {
        System.out.println("Invoking apiCodeLookup...");
        https.api_ewaypayments.CodeLookupRequest _apiCodeLookup_request = null;
        https.api_ewaypayments.CodeLookupResponse _apiCodeLookup__return = port.apiCodeLookup(_apiCodeLookup_request);
        System.out.println("apiCodeLookup.result=" + _apiCodeLookup__return);


        }
        {
        System.out.println("Invoking getAccessCodeResult...");
        https.api_ewaypayments.GetAccessCodeResultRequest _getAccessCodeResult_request = null;
        https.api_ewaypayments.GetAccessCodeResultResponse2 _getAccessCodeResult__return = port.getAccessCodeResult(_getAccessCodeResult_request);
        System.out.println("getAccessCodeResult.result=" + _getAccessCodeResult__return);


        }
        {
        System.out.println("Invoking directRefund...");
        https.api_ewaypayments.DirectRefundRequest _directRefund_request = null;
        https.api_ewaypayments.DirectRefundResponse2 _directRefund__return = port.directRefund(_directRefund_request);
        System.out.println("directRefund.result=" + _directRefund__return);


        }
        {
        System.out.println("Invoking capturePayment...");
        https.api_ewaypayments.CapturePaymentRequest _capturePayment_request = null;
        https.api_ewaypayments.CapturePaymentResponse2 _capturePayment__return = port.capturePayment(_capturePayment_request);
        System.out.println("capturePayment.result=" + _capturePayment__return);


        }
        {
        System.out.println("Invoking transactionSearch...");
        https.api_ewaypayments.TransactionSearchRequest _transactionSearch_request = null;
        https.api_ewaypayments.TransactionSearchResponse2 _transactionSearch__return = port.transactionSearch(_transactionSearch_request);
        System.out.println("transactionSearch.result=" + _transactionSearch__return);


        }

        System.exit(0);
    }

}
