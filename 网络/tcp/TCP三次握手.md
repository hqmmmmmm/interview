解释三次握手过程需要将客户端和服务器发送的数据包以及状态一起说。



TCP为什么需要三次握手
    3次握手可以确认客户端和服务端的接收和发送消息的能力是正常的。
    第一次握手确认客户端的发送能力是正常的，第二次握手确认了服务端接收和发送消息的能力是正常的，第三次握手确认了客户端的接收能力是正常的。



两次不行吗？
    超时的SYN报文到达又建立连接
    服务端的初始序列号没有得到确认