
# PostgreSQL package
Version: 13.3-2
```
wget https://get.enterprisedb.com/postgresql/postgresql-13.3-2-windows-x64-binaries.zip
```
# About RunHiddenConsole
https://www.nginx.com/resources/wiki/start/topics/examples/phpfastcgionwindows/  
https://redmine.lighttpd.net/attachments/660/RunHiddenConsole.zip  
https://redmine.lighttpd.net/attachments/download/660/RunHiddenConsole.zip  

# Working Directory
Master: C:/Users/nfeng/tools/pgsql

Replica: C:/Users/nfeng/tools/pgsql2
# Scripts
## INIT DB
```
C:/Users/nfeng/tools/pgsql/bin/pg_ctl init -D C:/Users/nfeng/tools/pgsql/data
```
## Start Master DB
```
C:/Users/nfeng/tools/RunHiddenConsole C:/Users/nfeng/tools/pgsql/bin/pg_ctl -D C:/Users/nfeng/tools/pgsql/data -l C:/Users/nfeng/pgsql.log start
```
## Stop Master DB
```
C:/Users/nfeng/tools/RunHiddenConsole C:/Users/nfeng/tools/pgsql/bin/pg_ctl -D C:/Users/nfeng/tools/pgsql/data stop
```
## Login Master DB
```
C:/Users/nfeng/tools/pgsql/bin/psql -dpostgres
```
## Create Super User On Master DB
```
create user root superuser password 'root';
```
## Login Master DB with root
```
C:/Users/nfeng/tools/pgsql/bin/psql -dpostgres -Uroot -W
Type: root
```
## Login with host
```
C:/Users/nfeng/tools/pgsql/bin/psql -dpostgres -hlocalhost -p5432 -Uroot -W
C:/Users/nfeng/tools/pgsql/bin/psql -dpostgres -h127.0.0.1 -p5432 -Uroot -W
C:/Users/nfeng/tools/pgsql/bin/psql -dpostgres -h10.110.14.166 -p5432 -Uroot -W
```
-h10.110.14.166 will fail, because "#listen_addresses = 'localhost'",
listen_addresses = '*' can allow it
## Checking Status
```
netstat -an | grep LISTEN

netstat -an | grep 5432

tasklist | grep postgres

taskkill /f /im postgres
```
## Backup from Master to Replica
Just stop master, then copy data folder to replica. And replace some settings in **postgresql.conf**. But remember to remove **postmaster.opts** and **postmaster.pid**.
## Start Replica DB
```
C:/Users/nfeng/tools/RunHiddenConsole C:/Users/nfeng/tools/pgsql2/bin/pg_ctl -D C:/Users/nfeng/tools/pgsql2/data -l C:/Users/nfeng/pgsql2.log start
```
## Stop Replica DB
```
C:/Users/nfeng/tools/RunHiddenConsole C:/Users/nfeng/tools/pgsql2/bin/pg_ctl -D C:/Users/nfeng/tools/pgsql2/data stop
```
## Login on Replica
```
C:/Users/nfeng/tools/pgsql2/bin/psql -dpostgres -p15432

C:/Users/nfeng/tools/pgsql2/bin/psql -dpostgres -p15432 -Uroot -W
Type: root
```
# Configuration

## Put file *standby.signal* in Replica data/
```
touch C:/Users/nfeng/tools/pgsql2/data/standby.signal
```

## Based on WAL (Write-Ahead Log) File Mode

| Field\Server | Master | Replica | Default |
| --- | --- | --- | --- |
| port | 5432 | 15432 | 5432 |
| archive_mode | on | off | off |
| archive_command | 'copy "%p" "C:/Users/nfeng/tools/archivedir/%f"' | '' | '' |
| archive_timeout | 10s | 0 | 0 |
| restore_command | '' | 'copy C:/Users/nfeng/tools/archivedir/%f %p' | '' |
| archive_cleanup_command | '' | 'C:/Users/nfeng/tools/pgsql2/bin/pg_archivecleanup C:/Users/nfeng/tools/archivedir %r' | '' |
| primary_conninfo | '' | 'host=127.0.0.1 port=5432 user=root password=root' | '' |


[archive_command、restore_command 的常见设置](https://blog.csdn.net/ctypyb2002/article/details/82702174)
Create archive Directory:
```
mkdir C:/Users/nfeng/tools/archivedir
```

Master Log (WAL File Mode)
```
已复制         1 个文件。
已复制         1 个文件。
已复制         1 个文件。
已复制         1 个文件。
已复制         1 个文件。
已复制         1 个文件。
```

Replica Log (WAL File Mode)
```
cp: stat‘D:/pgsql-archive/000000010000000000000005’失败: No such file or directory
cp: stat‘D:/pgsql-archive/00000002.history’失败: No such file or directory
2021-05-28 21:53:46.100 HKT [4352] 日志:  从归档中恢复日志文件 "000000010000000000000005"
cp: stat‘D:/pgsql-archive/000000010000000000000006’失败: No such file or directory
cp: stat‘D:/pgsql-archive/00000002.history’失败: No such file or directory
cp: stat‘D:/pgsql-archive/000000010000000000000006’失败: No such file or directory
cp: stat‘D:/pgsql-archive/00000002.history’失败: No such file or directory
2021-05-28 21:53:58.455 HKT [4352] 日志:  从归档中恢复日志文件 "000000010000000000000006"
cp: stat‘D:/pgsql-archive/000000010000000000000007’失败: No such file or directory
cp: stat‘D:/pgsql-archive/00000002.history’失败: No such file or directory
cp: stat‘D:/pgsql-archive/000000010000000000000007’失败: No such file or directory
cp: stat‘D:/pgsql-archive/00000002.history’失败: No such file or directory
2021-05-28 21:54:10.092 HKT [4352] 日志:  从归档中恢复日志文件 "000000010000000000000007"
...
2021-05-28 22:10:20.200 HKT [1072] 日志:  正在进入备用模式
2021-05-28 22:10:20.326 HKT [1072] 日志:  从归档中恢复日志文件 "00000001000000000000001D"
2021-05-28 22:10:20.655 HKT [1072] 日志:  从归档中恢复日志文件 "00000001000000000000001B"
2021-05-28 22:10:20.721 HKT [1072] 日志:  redo 在 0/1B022C00 开始
2021-05-28 22:10:20.890 HKT [1072] 日志:  从归档中恢复日志文件 "00000001000000000000001C"
2021-05-28 22:10:21.082 HKT [1072] 日志:  从归档中恢复日志文件 "00000001000000000000001D"
2021-05-28 22:10:21.148 HKT [1072] 日志:  在0/1E000000上已到达一致性恢复状态
2021-05-28 22:10:21.155 HKT [9332] 日志:  数据库系统准备接受只读请求的连接
cp: stat‘D:/pgsql-archive/00000001000000000000001E’失败: No such file or directory
2021-05-28 22:10:21.518 HKT [6776] 日志:  在时间点: 0/1E000000 (时间安排1)启动日志的流操作
2021-05-28 22:12:45.086 HKT [6776] 日志:  复制由主用服务器终止
2021-05-28 22:12:45.086 HKT [6776] 详细信息:  WAL结束时，到了时间线1和地址0/280000A0.
```

## Based on Stream Mode

| Field\Server | Master | Replica | Default |
| --- | --- | --- | --- |
| port | 5432 | 15432 | 5432 |
| primary_conninfo | '' | 'host=127.0.0.1 port=5432 user=root password=root' | '' |

> Notice
> 
> If primary_conninfo is set, it would use stream replication mode, otherwise use WAL File Mode.
> 
> Then archive_timeout is not needed or recommended in stream mode, in stream mode, the archivedir would keep empty always.

Replica Log (Stream mode)
```
2021-05-28 22:13:10.301 HKT [4268] 日志:  正在启动 PostgreSQL 13.3, compiled by Visual C++ build 1914, 64-bit
2021-05-28 22:13:10.312 HKT [4268] 日志:  正在监听IPv6地址"::1"，端口 15432
2021-05-28 22:13:10.312 HKT [4268] 日志:  正在监听IPv4地址"127.0.0.1"，端口 15432
2021-05-28 22:13:10.604 HKT [10176] 日志:  在2021-05-28 22:12:46 HKT，数据库在恢复中关闭
cp: stat‘D:/pgsql-archive/00000002.history’失败: No such file or directory
2021-05-28 22:13:10.659 HKT [10176] 日志:  正在进入备用模式
cp: stat‘D:/pgsql-archive/000000010000000000000028’失败: No such file or directory
2021-05-28 22:13:10.717 HKT [10176] 日志:  在0/280000A0上已到达一致性恢复状态
2021-05-28 22:13:10.718 HKT [10176] 日志:  在0/280000A0处的资源管理器ID97不合法
2021-05-28 22:13:10.751 HKT [4268] 日志:  数据库系统准备接受只读请求的连接
2021-05-28 22:13:11.214 HKT [6272] 日志:  在时间点: 0/28000000 (时间安排1)启动日志的流操作
2021-05-28 22:13:24.865 HKT [10176] 日志:  redo 在 0/280000A0 开始
```

[26.2.4. 建立一个后备服务器](http://www.postgres.cn/docs/12/warm-standby.html#STANDBY-SERVER-SETUP)  

## SQL
```
create table customer (
	id integer generated by default as identity,
	name varchar(32) not null,
	pwd varchar(255) not null,
	fname varchar(32) not null,
	lname varchar(32) not null,
	birth varchar(255) not null,
	weight varchar(255) not null,
	email varchar(255),
	primary key (id)
);

select count(1) from customer;

select * from customer order by id desc limit 10;

```
# 级联复制
pgsql(5432) -> pgsql2(15432) -> pgsql3(25432)

Copy pgsql1 to pgsql2, include bin/ data/ lib/ share/

| Field\Server | Master pgsql 5432 | Replica pgsql2 15432 | Replica pgsql3 25432 | Default |
| --- | --- | --- | --- | --- |
| port | 5432 | 15432 | 25432 | 5432 |
| archive_mode | on | on | off | off |
| archive_command | 'copy "%p" "C:/Users/nfeng/tools/archivedir/%f"' | 'copy "%p" "C:/Users/nfeng/tools/archivedir2/%f"' | '' | '' |
| restore_command | '' | 'copy C:/Users/nfeng/tools/archivedir/%f %p' | 'copy C:/Users/nfeng/tools/archivedir2/%f %p' | '' |
| archive_cleanup_command | '' | 'C:/Users/nfeng/tools/pgsql2/bin/pg_archivecleanup C:/Users/nfeng/tools/archivedir %r' | 'C:/Users/nfeng/tools/pgsql3/bin/pg_archivecleanup C:/Users/nfeng/tools/archivedir2 %r' | '' |
| primary_conninfo | '' | 'host=127.0.0.1 port=5432 user=root password=root' | 'host=127.0.0.1 port=5432 user=root password=root' | '' |

Create archive Directory:
```
mkdir C:/Users/nfeng/tools/archivedir2
```
## Put file *standby.signal* in Replica pgsql1 & pgsql2 data/