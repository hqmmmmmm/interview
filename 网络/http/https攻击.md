https中间人攻击发生在TLS握手阶段。

即SSL证书欺骗，攻击者将自己接入到浏览器和服务器之间，将服务器发给浏览器的SSL证书替换掉，浏览器就会使用攻击者的密钥加密数据，攻击者接收到就能用自己的私钥解密了。