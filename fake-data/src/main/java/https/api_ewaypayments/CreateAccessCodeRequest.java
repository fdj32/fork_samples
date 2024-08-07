
package https.api_ewaypayments;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlSchemaType;
import javax.xml.bind.annotation.XmlSeeAlso;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for CreateAccessCodeRequest complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="CreateAccessCodeRequest"&gt;
 *   &lt;complexContent&gt;
 *     &lt;extension base="{https://api.ewaypayments.com/}BaseRequest"&gt;
 *       &lt;sequence&gt;
 *         &lt;element name="Customer" type="{https://api.ewaypayments.com/}Customer" minOccurs="0"/&gt;
 *         &lt;element name="ShippingAddress" type="{https://api.ewaypayments.com/}ShippingAddress" minOccurs="0"/&gt;
 *         &lt;element name="Items" type="{https://api.ewaypayments.com/}ArrayOfLineItem" minOccurs="0"/&gt;
 *         &lt;element name="Options" type="{https://api.ewaypayments.com/}ArrayOfOption" minOccurs="0"/&gt;
 *         &lt;element name="Payment" type="{https://api.ewaypayments.com/}Payment" minOccurs="0"/&gt;
 *         &lt;element name="RedirectUrl" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CancelUrl" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CheckoutUrl" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="CustomerIP" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="DeviceID" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="PartnerID" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="Method" type="{https://api.ewaypayments.com/}Method"/&gt;
 *         &lt;element name="TrackingID" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/&gt;
 *         &lt;element name="TransactionType" type="{https://api.ewaypayments.com/}TransactionTypes" minOccurs="0"/&gt;
 *         &lt;element name="PaymentType" type="{https://api.ewaypayments.com/}PaymentType" minOccurs="0"/&gt;
 *         &lt;element name="CheckoutPayment" type="{http://www.w3.org/2001/XMLSchema}boolean" minOccurs="0"/&gt;
 *       &lt;/sequence&gt;
 *     &lt;/extension&gt;
 *   &lt;/complexContent&gt;
 * &lt;/complexType&gt;
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "CreateAccessCodeRequest", propOrder = {
    "customer",
    "shippingAddress",
    "items",
    "options",
    "payment",
    "redirectUrl",
    "cancelUrl",
    "checkoutUrl",
    "customerIP",
    "deviceID",
    "partnerID",
    "method",
    "trackingID",
    "transactionType",
    "paymentType",
    "checkoutPayment"
})
@XmlSeeAlso({
    CreateAccessCodeSharedRequest.class
})
public class CreateAccessCodeRequest
    extends BaseRequest
{

    @XmlElement(name = "Customer")
    protected Customer customer;
    @XmlElement(name = "ShippingAddress")
    protected ShippingAddress shippingAddress;
    @XmlElement(name = "Items")
    protected ArrayOfLineItem items;
    @XmlElement(name = "Options")
    protected ArrayOfOption options;
    @XmlElement(name = "Payment")
    protected Payment payment;
    @XmlElement(name = "RedirectUrl")
    protected String redirectUrl;
    @XmlElement(name = "CancelUrl")
    protected String cancelUrl;
    @XmlElement(name = "CheckoutUrl", defaultValue = "")
    protected String checkoutUrl;
    @XmlElement(name = "CustomerIP")
    protected String customerIP;
    @XmlElement(name = "DeviceID")
    protected String deviceID;
    @XmlElement(name = "PartnerID")
    protected String partnerID;
    @XmlElement(name = "Method", required = true)
    @XmlSchemaType(name = "string")
    protected Method method;
    @XmlElement(name = "TrackingID")
    protected String trackingID;
    @XmlElement(name = "TransactionType", defaultValue = "Purchase")
    @XmlSchemaType(name = "string")
    protected TransactionTypes transactionType;
    @XmlElement(name = "PaymentType", defaultValue = "None")
    @XmlSchemaType(name = "string")
    protected PaymentType paymentType;
    @XmlElement(name = "CheckoutPayment", defaultValue = "false")
    protected Boolean checkoutPayment;

    /**
     * Gets the value of the customer property.
     * 
     * @return
     *     possible object is
     *     {@link Customer }
     *     
     */
    public Customer getCustomer() {
        return customer;
    }

    /**
     * Sets the value of the customer property.
     * 
     * @param value
     *     allowed object is
     *     {@link Customer }
     *     
     */
    public void setCustomer(Customer value) {
        this.customer = value;
    }

    /**
     * Gets the value of the shippingAddress property.
     * 
     * @return
     *     possible object is
     *     {@link ShippingAddress }
     *     
     */
    public ShippingAddress getShippingAddress() {
        return shippingAddress;
    }

    /**
     * Sets the value of the shippingAddress property.
     * 
     * @param value
     *     allowed object is
     *     {@link ShippingAddress }
     *     
     */
    public void setShippingAddress(ShippingAddress value) {
        this.shippingAddress = value;
    }

    /**
     * Gets the value of the items property.
     * 
     * @return
     *     possible object is
     *     {@link ArrayOfLineItem }
     *     
     */
    public ArrayOfLineItem getItems() {
        return items;
    }

    /**
     * Sets the value of the items property.
     * 
     * @param value
     *     allowed object is
     *     {@link ArrayOfLineItem }
     *     
     */
    public void setItems(ArrayOfLineItem value) {
        this.items = value;
    }

    /**
     * Gets the value of the options property.
     * 
     * @return
     *     possible object is
     *     {@link ArrayOfOption }
     *     
     */
    public ArrayOfOption getOptions() {
        return options;
    }

    /**
     * Sets the value of the options property.
     * 
     * @param value
     *     allowed object is
     *     {@link ArrayOfOption }
     *     
     */
    public void setOptions(ArrayOfOption value) {
        this.options = value;
    }

    /**
     * Gets the value of the payment property.
     * 
     * @return
     *     possible object is
     *     {@link Payment }
     *     
     */
    public Payment getPayment() {
        return payment;
    }

    /**
     * Sets the value of the payment property.
     * 
     * @param value
     *     allowed object is
     *     {@link Payment }
     *     
     */
    public void setPayment(Payment value) {
        this.payment = value;
    }

    /**
     * Gets the value of the redirectUrl property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getRedirectUrl() {
        return redirectUrl;
    }

    /**
     * Sets the value of the redirectUrl property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setRedirectUrl(String value) {
        this.redirectUrl = value;
    }

    /**
     * Gets the value of the cancelUrl property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCancelUrl() {
        return cancelUrl;
    }

    /**
     * Sets the value of the cancelUrl property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCancelUrl(String value) {
        this.cancelUrl = value;
    }

    /**
     * Gets the value of the checkoutUrl property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCheckoutUrl() {
        return checkoutUrl;
    }

    /**
     * Sets the value of the checkoutUrl property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCheckoutUrl(String value) {
        this.checkoutUrl = value;
    }

    /**
     * Gets the value of the customerIP property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getCustomerIP() {
        return customerIP;
    }

    /**
     * Sets the value of the customerIP property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setCustomerIP(String value) {
        this.customerIP = value;
    }

    /**
     * Gets the value of the deviceID property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getDeviceID() {
        return deviceID;
    }

    /**
     * Sets the value of the deviceID property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setDeviceID(String value) {
        this.deviceID = value;
    }

    /**
     * Gets the value of the partnerID property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getPartnerID() {
        return partnerID;
    }

    /**
     * Sets the value of the partnerID property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setPartnerID(String value) {
        this.partnerID = value;
    }

    /**
     * Gets the value of the method property.
     * 
     * @return
     *     possible object is
     *     {@link Method }
     *     
     */
    public Method getMethod() {
        return method;
    }

    /**
     * Sets the value of the method property.
     * 
     * @param value
     *     allowed object is
     *     {@link Method }
     *     
     */
    public void setMethod(Method value) {
        this.method = value;
    }

    /**
     * Gets the value of the trackingID property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getTrackingID() {
        return trackingID;
    }

    /**
     * Sets the value of the trackingID property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setTrackingID(String value) {
        this.trackingID = value;
    }

    /**
     * Gets the value of the transactionType property.
     * 
     * @return
     *     possible object is
     *     {@link TransactionTypes }
     *     
     */
    public TransactionTypes getTransactionType() {
        return transactionType;
    }

    /**
     * Sets the value of the transactionType property.
     * 
     * @param value
     *     allowed object is
     *     {@link TransactionTypes }
     *     
     */
    public void setTransactionType(TransactionTypes value) {
        this.transactionType = value;
    }

    /**
     * Gets the value of the paymentType property.
     * 
     * @return
     *     possible object is
     *     {@link PaymentType }
     *     
     */
    public PaymentType getPaymentType() {
        return paymentType;
    }

    /**
     * Sets the value of the paymentType property.
     * 
     * @param value
     *     allowed object is
     *     {@link PaymentType }
     *     
     */
    public void setPaymentType(PaymentType value) {
        this.paymentType = value;
    }

    /**
     * Gets the value of the checkoutPayment property.
     * 
     * @return
     *     possible object is
     *     {@link Boolean }
     *     
     */
    public Boolean isCheckoutPayment() {
        return checkoutPayment;
    }

    /**
     * Sets the value of the checkoutPayment property.
     * 
     * @param value
     *     allowed object is
     *     {@link Boolean }
     *     
     */
    public void setCheckoutPayment(Boolean value) {
        this.checkoutPayment = value;
    }

}
