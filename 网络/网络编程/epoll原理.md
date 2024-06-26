epoll有3个API，epoll_cerate创建一个epoll实例，epoll_ctl修改epoll感兴趣的文件描述符，epoll_wait监听文件描述符，阻塞直到有就绪的文件描述符。

epoll是由红黑树和就绪链表实现的，epoll通过红黑树管理文件描述符，不会采用线性方式扫描文件描述符，而是采用回调机制，当文件描述符就绪时，回调函数会将其放到就绪链表中，当就绪链表不为空时，epoll_wait就会返回。同时epoll采用mmap的方式进行内核态和用户态的信息交换，避免了不必要的内存拷贝。epoll_wait会返回已经就绪的文件描述符数量，而且传出参数evs数组中只会有就绪的文件描述符对应的epoll_event，不需要遍历所有文件描述符。

epoll有两种工作模式：LT（水平触发），ET（边沿触发）。
水平触发是epoll默认的工作模式，比如说对于读事件来说，如果是水平触发模式，那么只要读缓冲区还有数据，读事件就会一直被触发，epoll_wait会直接返回；如果是边沿触发模式，那么只有当读缓冲区由空变为非空时，读事件才会触发，也就是说如果数据没有一次读完，读缓冲区还有数据，在边沿触发模式下，读事件是不会触发的，epoll_wait不会返回。所以边沿触发模式一般要循环读，确保将数据一次读完，同时还要将文件描述符设置为非阻塞的，防止读操作无意义的阻塞，非阻塞读在读完数据后后返回errno为EAGAIN，通过这个可以判断数据是否已经读完。