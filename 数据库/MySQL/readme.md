原子性：一个事务是一个不可分割的工作单位，一个事务中的所有操作要么都做，要么都不做。
一致性：事务操作前和操作后，数据都满足完整性约束，数据库保持一致的状态。
隔离性：事务内的操作对其他事务是隔离的，并发事务之间不能互相干扰。
持久新：事务对数据库的修改是永久性的，即使系统故障也不会丢失。


脏读：一个事务读到了另一个未提交事务修改的数据。       （读到其他事务未提交的数据）
不可重复读：一个事务内多次读取同一个数据，前后两次读到的数据不一样。  （前后读取的数据不一致）
幻读：一个事务内多次查询符合某个条件的记录数量，前后两次查询到的记录数是不一样的。  （前后读取的记录数量不一致）


读未提交
读提交
可重复读
串行化