TLS握手：SSL/TLS的建立过程，涉及四次通信。

---

ClientHello
    客户端支持的TLS协议版本
    客户端生成的随机数ClientRandom
    客户端支持的密码套件列表（即加密算法）

---

ServerHello
    确认TLS协议版本
    服务器产生的随机数ServerRandom
    确认密码套件
    服务器的SSL证书（其中包含公钥）

---

客户端回应（确认服务器的证书的真实性）
    生成一个随机数pre-master key(预主密钥), 会被服务器的公钥加密后再发送
    （此时客户端会通使用双方协商的加密算法和这三个随机数生成会话密钥。）
    加密通信算法改变通知，通知服务器之后都用会话密钥进行加密通信。
    客户端握手结束通知。
    
---

服务器的最后回应
    （服务器收到加密后的预主密钥后，通过自己的私钥便可得到预主密钥）
    （此时服务端也会使用双方协商的加密算法和这三个随机数生成会话密钥）
    加密通信算法改变通知，通知客户端以后都用会话密钥进行加密通信。
    服务器握手结束通知。

---

此后客户端和服务器之间的通信，就是基本使用普通的http协议，只不过使用会话密钥加密通信（对称加密）。