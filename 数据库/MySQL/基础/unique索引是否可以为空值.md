在sql server中，唯一索引字段不能出现多个null值

在mysql 的innodb引擎中，是允许在唯一索引的字段中出现多个null值的。

根据NULL的定义，NULL表示的是未知，因此两个NULL比较的结果既不相等，也不不等，结果仍然是未知。根据这个定义，多个NULL值的存在应该不违反唯一约束，所以是合理的，在oracel也是如此。



链接：https://www.jianshu.com/p/a3fb7d09af2a
