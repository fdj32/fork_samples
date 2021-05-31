# MySQL Replication
[Download mysql-8.0.25-winx64.zip](https://cdn.mysql.com//Downloads/MySQL-8.0/mysql-8.0.25-winx64.zip)  

# Reference
https://dev.mysql.com/doc/refman/8.0/en/replication.html  
https://computingforgeeks.com/configure-mysql-8-master-slave-replication-on-ubuntu/  
https://blog.monyog.com/setting-basic-master-slave-replication-mysql-8/  
https://www.tecmint.com/setup-mysql-master-slave-replication-on-rhel-8/  
https://hevodata.com/learn/mysql-master-slave-replication/  
https://severalnines.com/resources/database-management-tutorials/mysql-replication-high-availability-tutorial  
https://www.cnblogs.com/zhenyuyaodidiao/p/4635458.html  
https://severalnines.com/blog/top-mistakes-avoid-mysql-replication  
https://lefred.be/content/master-slave-replication-with-mysql-8-0-in-2-mins/  
http://lampblogs.com/blog/how-to-configure-mysql-80-master-slave-on-centos-7  
https://dev.mysql.com/doc/refman/8.0/en/change-master-to.html  

# Steps

## 1. Setting Up The Master

- Initiate master data directory
```
C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysqld -I -h C:/Users/nfeng/mysql-master-data
```
- Start master server
```
C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysqld -h C:/Users/nfeng/mysql-master-data
```
- Check root temporary password  
Log file: C:/Users/nfeng/mysql-master-data/XIA24971W.err  
PID file: C:/Users/nfeng/mysql-master-data/XIA24971W.pid  
```
2021-05-31T01:56:25.757808Z 0 [System] [MY-013169] [Server] C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysqld (mysqld 8.0.25) initializing of server in progress as process 23876
2021-05-31T01:56:25.782702Z 1 [System] [MY-013576] [InnoDB] InnoDB initialization has started.
2021-05-31T01:56:27.993546Z 1 [System] [MY-013577] [InnoDB] InnoDB initialization has ended.
2021-05-31T01:56:32.278462Z 6 [Note] [MY-010454] [Server] A temporary password is generated for root@localhost: n?37xi912H(o
2021-05-31T02:06:47.114629Z 0 [System] [MY-010116] [Server] C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysqld (mysqld 8.0.25) starting as process 3456
2021-05-31T02:06:47.143786Z 1 [System] [MY-013576] [InnoDB] InnoDB initialization has started.
2021-05-31T02:06:47.671176Z 1 [System] [MY-013577] [InnoDB] InnoDB initialization has ended.
2021-05-31T02:06:47.958748Z 0 [System] [MY-011323] [Server] X Plugin ready for connections. Bind-address: '::' port: 33060
2021-05-31T02:06:48.261529Z 0 [Warning] [MY-010068] [Server] CA certificate ca.pem is self signed.
2021-05-31T02:06:48.263200Z 0 [System] [MY-013602] [Server] Channel mysql_main configured to support TLS. Encrypted connections are now supported for this channel.
2021-05-31T02:06:48.307183Z 0 [System] [MY-010931] [Server] C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysqld: ready for connections. Version: '8.0.25'  socket: ''  port: 3306  MySQL Community Server - GPL.
```
- Login with temporary password
```
C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysql -uroot -p
Type: n?37xi912H(o
```
- reset password
```
ALTER USER "root"@"localhost" IDENTIFIED BY "root";

mysql> ALTER USER "root"@"localhost" IDENTIFIED BY "root";
Query OK, 0 rows affected (0.03 sec)
```
## 2. Create A New User For Slave
- Create slave user on master
```
CREATE USER "slave"@"localhost" IDENTIFIED BY "slave";
GRANT REPLICATION SLAVE ON *.* TO "slave"@"localhost";
GRANT REPLICATION CLIENT ON *.* TO "slave"@"localhost";
RESET MASTER;
SHOW GRANTS FOR 'slave'@'localhost';
SHOW MASTER STATUS;

mysql> CREATE USER "slave"@"localhost" IDENTIFIED BY "slave";
Query OK, 0 rows affected (0.02 sec)

mysql> GRANT REPLICATION SLAVE ON *.* TO "slave"@"localhost";
Query OK, 0 rows affected (0.01 sec)

mysql> GRANT REPLICATION CLIENT ON *.* TO "slave"@"localhost";
Query OK, 0 rows affected (0.01 sec)

mysql> RESET MASTER;
Query OK, 0 rows affected (0.05 sec)

mysql> SHOW GRANTS FOR 'slave'@'localhost';
+---------------------------------------------------------------------------+
| Grants for slave@localhost                                                |
+---------------------------------------------------------------------------+
| GRANT REPLICATION SLAVE, REPLICATION CLIENT ON *.* TO `slave`@`localhost` |
+---------------------------------------------------------------------------+
1 row in set (0.01 sec)

mysql> SHOW MASTER STATUS;
+---------------+----------+--------------+------------------+-------------------+
| File          | Position | Binlog_Do_DB | Binlog_Ignore_DB | Executed_Gtid_Set |
+---------------+----------+--------------+------------------+-------------------+
| binlog.000001 |      156 |              |                  |                   |
+---------------+----------+--------------+------------------+-------------------+
1 row in set (0.00 sec)

```
- check slave login on master
```
C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysql -uslave -p
Type: slave
```
## 3. Setting Up The Slave
> Notice
> 
> We are creating replication from empty data, so there isnot need to backup data from master then restore to slave.

- Initiate slave data directory
```
C:/Users/nfeng/mysql-slave/mysql-8.0.25-winx64/bin/mysqld -I -h C:/Users/nfeng/mysql-slave-data
```
- Start slave server
> Notice
> 
>  --server-id=2 --port=13306 --mysqlx-port=33061
```
C:/Users/nfeng/mysql-slave/mysql-8.0.25-winx64/bin/mysqld -h C:/Users/nfeng/mysql-slave-data --server-id=2 --port=13306 --mysqlx-port=33061
```
- Check root temporary password  
Log file: C:/Users/nfeng/mysql-slave-data/XIA24971W.err  
PID file: C:/Users/nfeng/mysql-slave-data/XIA24971W.pid  
```
2021-05-31T05:17:45.666251Z 0 [System] [MY-013169] [Server] C:/Users/nfeng/mysql-slave/mysql-8.0.25-winx64/bin/mysqld (mysqld 8.0.25) initializing of server in progress as process 20164
2021-05-31T05:17:45.685987Z 1 [System] [MY-013576] [InnoDB] InnoDB initialization has started.
2021-05-31T05:17:47.672896Z 1 [System] [MY-013577] [InnoDB] InnoDB initialization has ended.
2021-05-31T05:17:51.637383Z 6 [Note] [MY-010454] [Server] A temporary password is generated for root@localhost: /IAQwS(id48c
2021-05-31T05:18:26.260613Z 0 [System] [MY-010116] [Server] C:/Users/nfeng/mysql-slave/mysql-8.0.25-winx64/bin/mysqld (mysqld 8.0.25) starting as process 21460
2021-05-31T05:18:26.298180Z 1 [System] [MY-013576] [InnoDB] InnoDB initialization has started.
2021-05-31T05:18:26.961843Z 1 [System] [MY-013577] [InnoDB] InnoDB initialization has ended.
2021-05-31T05:18:27.211139Z 0 [System] [MY-011323] [Server] X Plugin ready for connections. Bind-address: '::' port: 33061
2021-05-31T05:18:27.445833Z 0 [Warning] [MY-010068] [Server] CA certificate ca.pem is self signed.
2021-05-31T05:18:27.447670Z 0 [System] [MY-013602] [Server] Channel mysql_main configured to support TLS. Encrypted connections are now supported for this channel.
2021-05-31T05:18:27.492650Z 0 [System] [MY-010931] [Server] C:/Users/nfeng/mysql-slave/mysql-8.0.25-winx64/bin/mysqld: ready for connections. Version: '8.0.25'  socket: ''  port: 13306  MySQL Community Server - GPL.
```
- Login with temporary password
```
C:/Users/nfeng/mysql-slave/mysql-8.0.25-winx64/bin/mysql -P13306 -uroot -p
Type: /IAQwS(id48c
```
- reset password
```
mysql> ALTER USER "root"@"localhost" IDENTIFIED BY "root";
Query OK, 0 rows affected (0.02 sec)

mysql> FLUSH PRIVILEGES;
Query OK, 0 rows affected (0.01 sec)

mysql> FLUSH TABLES WITH READ LOCK;
Query OK, 0 rows affected (0.00 sec)

mysql> \q
Bye

C:/Users/nfeng/mysql-slave/mysql-8.0.25-winx64/bin/mysql -P13306 -uroot -p
Type: root

C:\Users\nfeng>netstat -an | grep 3306
  TCP    0.0.0.0:3306           0.0.0.0:0              LISTENING
  TCP    0.0.0.0:13306          0.0.0.0:0              LISTENING
  TCP    0.0.0.0:33060          0.0.0.0:0              LISTENING
  TCP    0.0.0.0:33061          0.0.0.0:0              LISTENING
  TCP    [::]:3306              [::]:0                 LISTENING
  TCP    [::]:13306             [::]:0                 LISTENING
  TCP    [::]:33060             [::]:0                 LISTENING
  TCP    [::]:33061             [::]:0                 LISTENING
  TCP    [::1]:3306             [::1]:60691            ESTABLISHED
  TCP    [::1]:60691            [::1]:3306             ESTABLISHED

C:\Users\nfeng>
```
## 4. Restart Slave with --read-only
```
C:/Users/nfeng/mysql-slave/mysql-8.0.25-winx64/bin/mysqld -h C:/Users/nfeng/mysql-slave-data --server-id=2 --port=13306 --mysqlx-port=33061 --read-only
```
## 5. Run [CHANGE MASTER TO](https://dev.mysql.com/doc/refman/8.0/en/change-master-to.html) on slave
```
CHANGE MASTER TO MASTER_HOST='localhost', MASTER_PORT=3306, MASTER_USER='slave', MASTER_PASSWORD='slave', MASTER_LOG_FILE='binlog.000002', MASTER_LOG_POS=156;
```
> Notice
> 
> You must run [SHOW MASTER STATUS;](https://dev.mysql.com/doc/refman/8.0/en/show-master-status.html) right before [CHANGE MASTER TO](https://dev.mysql.com/doc/refman/8.0/en/change-master-to.html). Because MASTER_LOG_FILE and MASTER_LOG_POS may be changed.
## 6. Run [START SLAVE;](https://dev.mysql.com/doc/refman/8.0/en/start-slave.html) on slave
```
mysql> start slave;
Query OK, 0 rows affected, 1 warning (0.01 sec)

mysql> show slave status\G
*************************** 1. row ***************************
               Slave_IO_State: Waiting for master to send event
                  Master_Host: localhost
                  Master_User: slave
                  Master_Port: 3306
                Connect_Retry: 60
              Master_Log_File: binlog.000002
          Read_Master_Log_Pos: 156
               Relay_Log_File: XIA24971W-relay-bin.000002
                Relay_Log_Pos: 321
        Relay_Master_Log_File: binlog.000002
             Slave_IO_Running: Yes
            Slave_SQL_Running: Yes
...
```
# Verify
## DDL
- Create database, table on master
```
show databases;
CREATE DATABASE fake;
use fake;
create table customer (
	id INT NOT NULL AUTO_INCREMENT,
	name varchar(32) not null,
	pwd varchar(255) not null,
	fname varchar(32) not null,
	lname varchar(32) not null,
	birth varchar(255) not null,
	weight varchar(255) not null,
	email varchar(255),
	primary key (id)
);


mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
4 rows in set (0.01 sec)

mysql> CREATE DATABASE fake;
Query OK, 1 row affected (0.02 sec)

mysql> use fake;
Database changed
mysql> create table customer (
    -> id INT NOT NULL AUTO_INCREMENT,
    -> name varchar(32) not null,
    -> pwd varchar(255) not null,
    -> fname varchar(32) not null,
    -> lname varchar(32) not null,
    -> birth varchar(255) not null,
    -> weight varchar(255) not null,
    -> email varchar(255),
    -> primary key (id)
    -> );
Query OK, 0 rows affected (0.10 sec)

mysql> show tables;
+----------------+
| Tables_in_fake |
+----------------+
| customer       |
+----------------+
1 row in set (0.01 sec)

mysql> desc customer
    -> ;
+--------+--------------+------+-----+---------+----------------+
| Field  | Type         | Null | Key | Default | Extra          |
+--------+--------------+------+-----+---------+----------------+
| id     | int          | NO   | PRI | NULL    | auto_increment |
| name   | varchar(32)  | NO   |     | NULL    |                |
| pwd    | varchar(255) | NO   |     | NULL    |                |
| fname  | varchar(32)  | NO   |     | NULL    |                |
| lname  | varchar(32)  | NO   |     | NULL    |                |
| birth  | varchar(255) | NO   |     | NULL    |                |
| weight | varchar(255) | NO   |     | NULL    |                |
| email  | varchar(255) | YES  |     | NULL    |                |
+--------+--------------+------+-----+---------+----------------+
8 rows in set (0.01 sec)
```
- Verify on slave
```
mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| fake               |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
5 rows in set (0.01 sec)

mysql> use fake;
Database changed
mysql> show tables;
+----------------+
| Tables_in_fake |
+----------------+
| customer       |
+----------------+
1 row in set (0.01 sec)

mysql> desc customer;
+--------+--------------+------+-----+---------+----------------+
| Field  | Type         | Null | Key | Default | Extra          |
+--------+--------------+------+-----+---------+----------------+
| id     | int          | NO   | PRI | NULL    | auto_increment |
| name   | varchar(32)  | NO   |     | NULL    |                |
| pwd    | varchar(255) | NO   |     | NULL    |                |
| fname  | varchar(32)  | NO   |     | NULL    |                |
| lname  | varchar(32)  | NO   |     | NULL    |                |
| birth  | varchar(255) | NO   |     | NULL    |                |
| weight | varchar(255) | NO   |     | NULL    |                |
| email  | varchar(255) | YES  |     | NULL    |                |
+--------+--------------+------+-----+---------+----------------+
8 rows in set (0.00 sec)
```
## DML
- Start fake-data project:
```
gradlew.bat build
java -jar build/libs/fake-data.jar
```
- Verify data inserted on master and replicated to slave
```
mysql> select * from customer order by id desc limit 10;
+--------+-----------+----------+-------+-------+------------+--------+---------------------+
| id     | name      | pwd      | fname | lname | birth      | weight | email               |
+--------+-----------+----------+-------+-------+------------+--------+---------------------+
| 195344 | Tom Hanks | P@ssw01d | Tom   | Hanks | 1951-06-20 | 84.9   | Tom.Hanks@gmail.com |
| 195343 | Tom Hanks | P@ssw01d | Tom   | Hanks | 1951-06-20 | 84.9   | Tom.Hanks@gmail.com |
| 195291 | Tom Hanks | P@ssw01d | Tom   | Hanks | 1951-06-20 | 84.9   | Tom.Hanks@gmail.com |
| 195246 | Tom Hanks | P@ssw01d | Tom   | Hanks | 1951-06-20 | 84.9   | Tom.Hanks@gmail.com |
| 195245 | Tom Hanks | P@ssw01d | Tom   | Hanks | 1951-06-20 | 84.9   | Tom.Hanks@gmail.com |
| 195173 | Tom Hanks | P@ssw01d | Tom   | Hanks | 1951-06-20 | 84.9   | Tom.Hanks@gmail.com |
| 195085 | Tom Hanks | P@ssw01d | Tom   | Hanks | 1951-06-20 | 84.9   | Tom.Hanks@gmail.com |
| 195084 | Tom Hanks | P@ssw01d | Tom   | Hanks | 1951-06-20 | 84.9   | Tom.Hanks@gmail.com |
| 194968 | Tom Hanks | P@ssw01d | Tom   | Hanks | 1951-06-20 | 84.9   | Tom.Hanks@gmail.com |
| 194917 | Tom Hanks | P@ssw01d | Tom   | Hanks | 1951-06-20 | 84.9   | Tom.Hanks@gmail.com |
+--------+-----------+----------+-------+-------+------------+--------+---------------------+
10 rows in set (0.00 sec)
```
The replication speed is slower than PostgreSQL on my machine with default settings.
# Use the same binary folder
```
C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysqld -h C:/Users/nfeng/mysql-slave-data --server-id=2 --port=13306 --mysqlx-port=33061 --read-only

C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysql -P13306 -uroot -p
```

# Multi-Slave and Cascading Replication
- Copy slave data folder [failed]
```
cp -r C:/Users/nfeng/mysql-slave-data C:/Users/nfeng/mysql-slave2-data
C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysqld -h C:/Users/nfeng/mysql-slave2-data --server-id=3 --port=23306 --mysqlx-port=33062 --read-only
C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysql -P23306 -uroot -p
```
Log has errors.
```
2021-05-31T08:18:39.518917Z 0 [System] [MY-010116] [Server] C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysqld (mysqld 8.0.25) starting as process 11924
2021-05-31T08:18:39.546843Z 1 [System] [MY-013576] [InnoDB] InnoDB initialization has started.
2021-05-31T08:18:40.546816Z 1 [System] [MY-013577] [InnoDB] InnoDB initialization has ended.
2021-05-31T08:18:40.751660Z 0 [System] [MY-011323] [Server] X Plugin ready for connections. Bind-address: '::' port: 33062
2021-05-31T08:18:40.804575Z 0 [System] [MY-010229] [Server] Starting XA crash recovery...
2021-05-31T08:18:40.836766Z 0 [System] [MY-010232] [Server] XA crash recovery finished.
2021-05-31T08:18:40.921634Z 0 [Warning] [MY-010068] [Server] CA certificate ca.pem is self signed.
2021-05-31T08:18:40.927246Z 0 [System] [MY-013602] [Server] Channel mysql_main configured to support TLS. Encrypted connections are now supported for this channel.
2021-05-31T08:18:40.999592Z 0 [Warning] [MY-010604] [Repl] Neither --relay-log nor --relay-log-index were used; so replication may break when this MySQL server acts as a slave and has his hostname changed!! Please use '--relay-log=XIA24971W-relay-bin' to avoid this problem.
2021-05-31T08:18:41.043512Z 5 [Warning] [MY-010897] [Repl] Storing MySQL user name or password information in the master info repository is not secure and is therefore not recommended. Please consider using the USER and PASSWORD connection options for START SLAVE; see the 'START SLAVE Syntax' in the MySQL Manual for more information.
2021-05-31T08:18:41.052791Z 0 [System] [MY-010931] [Server] C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysqld: ready for connections. Version: '8.0.25'  socket: ''  port: 23306  MySQL Community Server - GPL.
2021-05-31T08:18:41.055436Z 5 [ERROR] [MY-010584] [Repl] Slave I/O for channel '': error connecting to master 'slave@localhost:3306' - retry-time: 60 retries: 1 message: Authentication plugin 'caching_sha2_password' reported error: Authentication requires secure connection. Error_code: MY-002061
2021-05-31T08:19:41.072323Z 5 [ERROR] [MY-010584] [Repl] Slave I/O for channel '': error connecting to master 'slave@localhost:3306' - retry-time: 60 retries: 2 message: Authentication plugin 'caching_sha2_password' reported error: Authentication requires secure connection. Error_code: MY-002061


CHANGE MASTER TO MASTER_HOST='localhost', MASTER_PORT=3306, MASTER_USER='slave', MASTER_PASSWORD='slave', MASTER_LOG_FILE='binlog.000005', MASTER_LOG_POS=156;

mysql> CHANGE MASTER TO MASTER_HOST='localhost', MASTER_PORT=3306, MASTER_USER='slave', MASTER_PASSWORD='slave', MASTER_LOG_FILE='binlog.000005', MASTER_LOG_POS=156;
ERROR 3021 (HY000): This operation cannot be performed with a running slave io thread; run STOP SLAVE IO_THREAD FOR CHANNEL '' first.
mysql> STOP SLAVE IO_THREAD FOR CHANNEL '';
Query OK, 0 rows affected, 1 warning (0.01 sec)

mysql> CHANGE MASTER TO MASTER_HOST='localhost', MASTER_PORT=3306, MASTER_USER='slave', MASTER_PASSWORD='slave', MASTER_LOG_FILE='binlog.000005', MASTER_LOG_POS=156;
Query OK, 0 rows affected, 8 warnings (0.02 sec)

mysql>

2021-05-31T08:27:03.151539Z 10 [System] [MY-010597] [Repl] 'CHANGE MASTER TO FOR CHANNEL '' executed'. Previous state master_host='localhost', master_port= 3306, master_log_file='binlog.000002', master_log_pos= 80853073, master_bind=''. New state master_host='localhost', master_port= 3306, master_log_file='binlog.000005', master_log_pos= 156, master_bind=''.

```

```
auto.cnf need to change server-uuid ?
[auto]
server-uuid=67201892-51a1-4b0e-afe1-9f870838a661


C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysqld -h C:/Users/nfeng/mysql-slave-data --server-id=2 --port=13306 --mysqlx-port=33061 --read-only

2021-05-31T08:43:39.194366Z 0 [System] [MY-010116] [Server] C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysqld (mysqld 8.0.25) starting as process 6116
2021-05-31T08:43:39.221724Z 1 [System] [MY-013576] [InnoDB] InnoDB initialization has started.
2021-05-31T08:43:40.139311Z 1 [System] [MY-013577] [InnoDB] InnoDB initialization has ended.
2021-05-31T08:43:40.331684Z 0 [System] [MY-011323] [Server] X Plugin ready for connections. Bind-address: '::' port: 33061
2021-05-31T08:43:40.383493Z 0 [System] [MY-010229] [Server] Starting XA crash recovery...
2021-05-31T08:43:40.401587Z 0 [System] [MY-010232] [Server] XA crash recovery finished.
2021-05-31T08:43:40.476026Z 0 [Warning] [MY-010068] [Server] CA certificate ca.pem is self signed.
2021-05-31T08:43:40.477775Z 0 [System] [MY-013602] [Server] Channel mysql_main configured to support TLS. Encrypted connections are now supported for this channel.
2021-05-31T08:43:40.522796Z 0 [System] [MY-010931] [Server] C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysqld: ready for connections. Version: '8.0.25'  socket: ''  port: 13306  MySQL Community Server - GPL.

C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysql -uroot -p

SHOW MASTER STATUS;
+---------------+----------+--------------+------------------+-------------------+
| File          | Position | Binlog_Do_DB | Binlog_Ignore_DB | Executed_Gtid_Set |
+---------------+----------+--------------+------------------+-------------------+
| binlog.000007 |      156 |              |                  |                   |
+---------------+----------+--------------+------------------+-------------------+
1 row in set (0.00 sec)

mysql>


C:/Users/nfeng/mysql-8.0.25-winx64/bin/mysql -P13306 -uroot -p

CHANGE MASTER TO MASTER_HOST='localhost', MASTER_PORT=3306, MASTER_USER='slave', MASTER_PASSWORD='slave', MASTER_LOG_FILE='binlog.000007', MASTER_LOG_POS=156;

START SLAVE;

SHOW SLAVE STATUS\G

select * from customer order by id desc limit 10;


2021-05-31T08:47:57.953149Z 9 [Warning] [MY-010897] [Repl] Storing MySQL user name or password information in the master info repository is not secure and is therefore not recommended. Please consider using the USER and PASSWORD connection options for START SLAVE; see the 'START SLAVE Syntax' in the MySQL Manual for more information.
2021-05-31T08:47:57.966813Z 9 [ERROR] [MY-010584] [Repl] Slave I/O for channel '': error connecting to master 'slave@localhost:3306' - retry-time: 60 retries: 1 message: Authentication plugin 'caching_sha2_password' reported error: Authentication requires secure connection. Error_code: MY-002061
2021-05-31T08:48:57.975975Z 9 [ERROR] [MY-010584] [Repl] Slave I/O for channel '': error connecting to master 'slave@localhost:3306' - retry-time: 60 retries: 2 message: Authentication plugin 'caching_sha2_password' reported error: Authentication requires secure connection. Error_code: MY-002061


SET SQL_LOG_BIN=0;
alter USER 'slave'@'localhost' IDENTIFIED WITH sha256_password BY 'slave';
GRANT REPLICATION SLAVE ON *.* TO 'slave'@'localhost';
SET SQL_LOG_BIN=1;


mysql> SET SQL_LOG_BIN=0;
Query OK, 0 rows affected (0.00 sec)

mysql> alter USER 'slave'@'localhost' IDENTIFIED WITH sha256_password BY 'slave';
Query OK, 0 rows affected (0.02 sec)

mysql> GRANT REPLICATION SLAVE ON *.* TO 'slave'@'localhost';
Query OK, 0 rows affected (0.00 sec)

mysql> SET SQL_LOG_BIN=1;
Query OK, 0 rows affected (0.00 sec)

mysql>
```

https://www.cnblogs.com/liuqw/p/11759705.html  

