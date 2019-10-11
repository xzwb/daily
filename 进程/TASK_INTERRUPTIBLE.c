// Linux进程状态之可中断睡眠状态
// 处于这个状态的进程因为等待某某事件的发生（比如等待socket连接、等待信号量），而被挂起。这些进程的task_struct结构被放入对应事件的等待队列中。当这些事件发生时（由外部中断触发、或由其他进程触发），对应的等待队列中的一个或多个进程将被唤醒。


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <signal.h>

/* int main()
{
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(struct sockaddr_in));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8888);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in));
    listen(sock_fd, 12);
    int len = sizeof(struct sockaddr_in);
    accept(sock_fd, (struct sockaddr *)&cli_addr, &len);
} */

/* int main()
{
    sleep(10);
    return 0;
} */

// 信号不是信号量

void callback(int signo)
{
    printf("recv SIGNAL\n");
}

int main()
{
    signal(SIGINT, callback);

    while (1) {
    
    } 

    return 0;
}
