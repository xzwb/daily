// 信号量

#include <stdio.h>
#include <sys/sem.h>

// 创建信号集并对信号集中所有信号初始化
int creatsem(const char *pathname, int proj_id, int members, int init_val)
{
    key_t msgkey;
    int index, sid;
    union semun semopts;

    // 获取键值也就是semget()的第一个参数
    if ((msgkey = ftok(pathname, proj_id)) == -1) {
        perror("ftok error\n");
        return -1;
    }
    if ((sid = semget(msgkey, members, IPC_CREAT|IPC_EXCL)) == -1) {
        perror("semget call failed\n");
        return -1;
    }

    // 初始化操作
    semopts.bal = init_val;
    for (index = 0; index < members; ++index) {
        semctl(sid, index, SETVAL, sempots);
    }
    
    return sid;
}

// P操作如皋信号量的值大圩0，就给他减1，如果他的值为0，就挂起该进程的执行;
// v操作如果有其他进程因为等待信号量被挂起,就让他恢复运行,如果没有，就给他加一；

int sem_p(int semid, int index)
{
    struct sembuf buf = {0, -1, IPC_NOWAIT};

    if (index < 0) {
        perror("index < 0\n");
        return -1;
    }

    buf.sem_num = index;
    if (semop(semid, &buf, 1) == -1) {
        perror("error\n");
        return -1;
    }

    return 0;
}

int sem_v(int semid, int index)
{
    struct sembuf buf = {0, 1, IPC_NOWAIT};

    if (index < 0) {
        perror("cuowu\n");
        return -1;
    }

    buf.sem_num = index;
    if (semop(semid, &buf, 1) == -1) {
        perror("????\n");
        return -1;
    }

    return 0;
}
