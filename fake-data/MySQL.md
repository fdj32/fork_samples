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