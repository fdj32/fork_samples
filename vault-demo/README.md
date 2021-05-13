# vault-demo

A demo site for Vault integration.

# project/java-vault-demo/src/main/resources/bootstrap.yml
Localhost Vault Development Environment
```
spring:
  cloud:
    vault:
      host: localhost
      port: 8200
      scheme: http
      authentication: TOKEN
      token: s.RUTUkmNZhtPf3TuMcbA9LARM
```
Active Vault Development Environment
```	  
spring:
  cloud:
    vault:
      host: ea-poc-sm.poc.k8sw.dev.activenetwork.com
      port: 80
      scheme: http
      authentication: TOKEN
      token: s.NAmH4ypFbuuKBQCm4WFvQgz3
```
10.119.33.189
```	  
spring:
  cloud:
    vault:
      host: 10.119.33.189
      port: 8200
      scheme: http
      authentication: TOKEN
      token: s.IM2hGgmItSQA4gDl2S4uoZGG
```

# Deployment

## java spring boot jar on 10.119.33.189:8086
```
-bash-4.1$ more /opt/active/user/deploy/a_java_vault_demo.sh
/usr/java/jdk8_192-1.8_192/bin/java -jar ./java-vault-demo.jar &
-bash-4.1$
```

it will load nginx load balancer to 4 backends vault services
10.119.33.191:8300 is an nginx load balancer
```
spring:
  cloud:
    vault:
      host: 10.119.33.191
      port: 8300
      scheme: http
      authentication: TOKEN
      token: s.KJMEZZ1LQP8vmZptVKa7vQLV
```

## Nginx load balancer
```
-bash-4.1$ more /opt/active/user/deploy/tools/nginx-1.15.12/conf/nginx.conf
events {
    worker_connections  1024;
}

http {
    upstream int-vault {
        server 10.119.33.188:8200;
        server 10.119.33.189:8200;
        server 10.119.33.189:8200;
        server 10.119.33.189:8200;
    }
    server {
        listen 8300;
        location / {
            proxy_pass http://int-vault;
        }
    }
}
-bash-4.1$
```

## Vault on 10.119.33.188:8200, other servers change the ip property
### start server with .hcl config file
```
-bash-4.1$ more /opt/active/user/deploy/e_vault.sh
echo "Unseal Key 1: w3e2rQnVFAJj0ejZG+c/7rb4Xlmym++wCWoEcaJvdKuG "
echo "Unseal Key 2: SOYKtazcVCuLCviYfX+PKuJ0/gyZitfNfqlAThYwwqj0 "
echo "Unseal Key 3: XBsD5KNeVCs0ybIp34bRX/CIJrT9ydS/LsUk+3OEE6G1 "
echo "Unseal Key 4: Wxtl1RyC/4XkSnjG4XIyN1MkgZ7V8bo2LPqSJDqF8dN/ "
echo "Unseal Key 5: 4z+/Ze+92Re5WSzwhBbRmRTfmW/tBHkVb2CinAzzs+8M "
echo "Initial Root Token: s.KJMEZZ1LQP8vmZptVKa7vQLV "
/opt/active/user/deploy/tools/vault server -config=/opt/active/user/deploy/tools/188.hcl &
-bash-4.1$ more /opt/active/user/deploy/tools/188.hcl
listener "tcp" {
  address = "127.0.0.1:8200"
  tls_disable = true
}
listener "tcp" {
  address = "10.119.33.188:8200"
  tls_disable = true
}
storage "postgresql" {
  connection_url = "postgres://root:root@10.119.33.191:5432/vault?sslmode=disable"
}
api_addr = "http://127.0.0.1:8200"
cluster_addr = "http://127.0.0.1:8201"
ui = true
disable_mlock = true
disable_cache = true
-bash-4.1$

```

**disable_cache = true is to disable vault cache, it is useful in rotate key feature in cluster environment.**

### operator init
/home/nfeng/tool/vault operator init -address=http://10.119.33.238:8200
```
[nfeng@int-amsweb04w ~]$ /home/nfeng/tool/vault operator init -address=http://10.119.33.238:8200
2020-02-27T12:32:49.944Z [ERROR] core: no seal config found, can't determine if legacy or new-style shamir
2020-02-27T12:32:49.949Z [INFO]  core: security barrier not initialized
2020-02-27T12:32:50.075Z [INFO]  core: security barrier initialized: stored=1 shares=5 threshold=3
2020-02-27T12:32:50.132Z [INFO]  core: post-unseal setup starting
2020-02-27T12:32:50.162Z [INFO]  core: loaded wrapping token key
2020-02-27T12:32:50.162Z [INFO]  core: successfully setup plugin catalog: plugin-directory=
2020-02-27T12:32:50.163Z [INFO]  core: no mounts; adding default mount table
2020-02-27T12:32:50.188Z [INFO]  core: successfully mounted backend: type=cubbyhole path=cubbyhole/
2020-02-27T12:32:50.188Z [INFO]  core: successfully mounted backend: type=system path=sys/
2020-02-27T12:32:50.188Z [INFO]  core: successfully mounted backend: type=identity path=identity/
2020-02-27T12:32:50.261Z [INFO]  core: successfully enabled credential backend: type=token path=token/
2020-02-27T12:32:50.261Z [INFO]  core: restoring leases
2020-02-27T12:32:50.261Z [INFO]  rollback: starting rollback manager
2020-02-27T12:32:50.284Z [INFO]  identity: entities restored
2020-02-27T12:32:50.285Z [INFO]  identity: groups restored
2020-02-27T12:32:50.297Z [INFO]  core: post-unseal setup complete
2020-02-27T12:32:50.302Z [INFO]  expiration: lease restore complete
2020-02-27T12:32:50.313Z [INFO]  core: root token generated
2020-02-27T12:32:50.313Z [INFO]  core: pre-seal teardown starting
2020-02-27T12:32:50.313Z [INFO]  rollback: stopping rollback manager
2020-02-27T12:32:50.313Z [INFO]  core: pre-seal teardown complete
Unseal Key 1: 6MwEUwtLrsmxsW2iPCXxLfiBiXP6wx15gM6Fvj7O+nFM
Unseal Key 2: 0cMLvBaKCP0F/U58cvCY3dZna5VvMWVpp+dj4NE3JGYH
Unseal Key 3: nhzj20olsmsxcGFajWxEBHQ6Z2zklr1nibHNYJdf7SBr
Unseal Key 4: 7Y/e+zQI9FPXISPs2cP5Edk9xQrPtFj5LYuO77HGnCyE
Unseal Key 5: 02btgggXcPKbOWfcIo2qnWrSybvcVXfZmLL5SKZfSd8M

Initial Root Token: s.WtHfRrNiSt0fnguW35GMc7bO

Vault initialized with 5 key shares and a key threshold of 3. Please securely
distribute the key shares printed above. When the Vault is re-sealed,
restarted, or stopped, you must supply at least 3 of these keys to unseal it
before it can start servicing requests.

Vault does not store the generated master key. Without at least 3 key to
reconstruct the master key, Vault will remain permanently sealed!

It is possible to generate new unseal keys, provided you have a quorum of
existing unseal keys shares. See "vault operator rekey" for more information.
[nfeng@int-amsweb04w ~]$

```

## Postgres on 10.119.33.191

### start postgres server shell
```
-bash-4.1$ more /opt/active/user/deploy/pgsql.sh
################################################################
# /opt/active/user/deploy/tools/pgsql/bin/pg_ctl init -D /opt/active/user/deploy/tools/pgsql/data
# /opt/active/user/deploy/tools/pgsql/bin/pg_ctl -D /opt/active/user/deploy/tools/pgsql/data -l logfile restart &
################################################################
/opt/active/user/deploy/tools/pgsql/bin/pg_ctl -D /opt/active/user/deploy/tools/pgsql/data -l logfile start &
```

### create a user
```
/opt/active/user/deploy/tools/pgsql/bin/psql -dpostgres
create user root superuser password 'root';
psql -dpostgres -Uroot -W
root
```

### Allow servers other than localhost to connect

#### Bind to all IP
```
alter system set listen_addresses = '*';
```

#### allow client server ip 10.119.33.191/16
```
-bash-4.1$ more /opt/active/user/deploy/tools/pgsql/data/pg_hba.conf
# IPv4 local connections:
host    all             all             127.0.0.1/32            trust
host    all             all             10.119.33.191/16        trust
```

### Create Tables
https://www.vaultproject.io/docs/configuration/storage/postgresql/  


# Notice
Please start all servers, unseal all servers, enable transit on all servers, then create a key on transit, then it will be shared by other servers, otherwise not.

# Links
Vault Demo: http://10.119.33.189:8086/  
Nginx Load Balancer: http://10.119.33.191:8300/  
Vault Service on int 01: http://10.119.33.188:8200/  
Vault Service on int 02: http://10.119.33.189:8200/  
Vault Service on int 03: http://10.119.33.190:8200/  
Vault Service on int 04: http://10.119.33.191:8200/  

Use this token to login vault ui
Initial Root Token: s.KJMEZZ1LQP8vmZptVKa7vQLV

# Build thin jar
build.gradle

```
bootJar {
	classifier = 'boot'
	excludes = ["*.jar"]
}
```
Put BOOT-INT/lib/*.jar to /home/nfeng/java-vault-demo-lib, add java opt -Djava.ext.dirs=/home/nfeng/java-vault-demo-lib
```
$ more a_java-vault-demo.sh
# /usr/java/jdk8_192-1.8_192/bin/java -jar /home/nfeng/java-vault-demo.jar &

/usr/java/jdk8_192-1.8_192/bin/java -Djava.ext.dirs=/home/nfeng/java-vault-demo-lib -jar /home/nfeng/java-vault-demo-boot.jar &
$
```
