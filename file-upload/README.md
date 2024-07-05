# How to process file uploads in Go

This repo contains the complete code used in [this Freshman
tutorial](https://freshman.tech/file-upload-golang/). Clone this repo to your
computer and run `go run main.go` to start the server on PORT 4500.

# HTTPS

[golang https服务](https://blog.csdn.net/javahuazaili/article/details/122649644)

```
XIA34926M:file-upload nfeng$ openssl genrsa -out ca.key 2048
Generating RSA private key, 2048 bit long modulus
.......................
.
e is 65537 (0x010001)
XIA34926M:file-upload nfeng$ ls ca.key 
ca.key
XIA34926M:file-upload nfeng$ openssl req -x509 -new -nodes -key ca.key -subj "/CN=192.168.1.106" -days 5000 -out ca.crt
XIA34926M:file-upload nfeng$ ls 
LICENCE		README.md	ca.crt		ca.key		config		file-upload	go.mod		index.html	main.go		uploads
XIA34926M:file-upload nfeng$ openssl genrsa -out server.key 2048
Generating RSA private key, 2048 bit long modulus
.......................
...............................................
e is 65537 (0x010001)
XIA34926M:file-upload nfeng$ openssl req -new -key server.key -subj "/CN=192.168.1.106" -out server.csr
XIA34926M:file-upload nfeng$ echo subjectAltName = IP:192.168.1.106 > extfile.cnf
XIA34926M:file-upload nfeng$ openssl x509 -req -in server.csr -CA ca.crt -CAkey ca.key -CAcreateserial -extfile extfile.cnf -out server.crt -days 5000
Signature ok
subject=/CN=192.168.1.106
Getting CA Private Key
XIA34926M:file-upload nfeng$ ls
LICENCE		ca.crt		ca.srl		extfile.cnf	go.mod		main.go		server.csr	uploads
README.md	ca.key		config		file-upload	index.html	server.crt	server.key
XIA34926M:file-upload nfeng$ 
```