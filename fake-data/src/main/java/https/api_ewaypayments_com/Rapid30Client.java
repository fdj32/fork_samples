package https.api_ewaypayments_com;

import javax.xml.ws.BindingProvider;

import org.apache.cxf.configuration.security.AuthorizationPolicy;
import org.apache.cxf.endpoint.Client;
import org.apache.cxf.frontend.ClientProxy;
import org.apache.cxf.interceptor.LoggingInInterceptor;
import org.apache.cxf.interceptor.LoggingOutInterceptor;
import org.apache.cxf.transport.http.HTTPConduit;
import org.apache.cxf.transport.http.auth.DefaultBasicAuthSupplier;
import org.apache.cxf.transport.http.auth.HttpAuthSupplier;

import https.api_ewaypayments.DirectRefundRequest;
import https.api_ewaypayments.DirectTokenCustomer;

public class Rapid30Client {
	
	private static final String endPointAddress = "https://api.sandbox.ewaypayments.com/soap.asmx?WSDL";
	private static final String username = "A1001CMFVc9dLcgMuQehpUZMMaVYU4Ca5kkeEDnfI8BytlM2s5AhJqBNqemuF6jyCmo4uj";
	private static final String password = "101F0T2H";

	public static void main(String[] args) {
		Rapid30 rapid30 = new Rapid30();
		Rapid30Soap port = rapid30.getRapid30Soap();
		BindingProvider provider = (BindingProvider) port;
		provider.getRequestContext().put(
				BindingProvider.ENDPOINT_ADDRESS_PROPERTY, endPointAddress);
		Client client = ClientProxy.getClient(port);
		client.getOutInterceptors().add(new LoggingOutInterceptor());
		client.getInInterceptors().add(new LoggingInInterceptor());
		HTTPConduit http = (HTTPConduit) client.getConduit();
		AuthorizationPolicy authorization = new AuthorizationPolicy();
		authorization.setUserName(username);
		authorization.setPassword(password);
		http.setAuthorization(authorization);
		HttpAuthSupplier supplier = new DefaultBasicAuthSupplier();
		http.setAuthSupplier(supplier);
		/*
		CancelAuthorisationRequest req = new CancelAuthorisationRequest();
		req.setTransactionID(38852229);
		port.cancelAuthorisation(req);
		*/
		DirectRefundRequest req = new DirectRefundRequest();
		DirectTokenCustomer cus = new DirectTokenCustomer();
		cus.setCardNumber("4242424242424242");
		cus.setCardExpiryMonth("12");
		cus.setCardExpiryYear("2028");
		req.setCustomer(cus);
		// amount ?
		port.directRefund(req);
	}

}
