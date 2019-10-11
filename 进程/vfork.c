// 神奇的vfork,进程的D状态

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int add(int a, int b) 
{
    return a+b;
}

int main()
{
    int pid;
    int i = 0;
    pid = vfork();
    if (!pid) {
        // 查看D状态
        sleep(100);
        // printf("子进程\n");
        // printf("1 + 1 = %d\n", add(1, 1));
        // printf("%d\n", ++i);
        // vfork创建的子进程不具备写时复制能力所以不能修改栈上的数据上面三个实验都会在父进程返回时引发段错误;
        // return 0; 子进程不能返回因为vfork与fork不同没有自己的内存空间;
    }

    return 0;
} 

// fork对比

/* int main()
{
    int pid = fork();
    int i = 0;
    if (!pid) {
        printf("子进程\n");
        printf("%d\n", ++i);
        return 0;
    }

    return 0;
} */
