// 进程间通信信号量实例

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sem.h>

union semun 
{
	int val;   
	struct semid_ds  *buf;  
	unsigned short *array;
};

int main()
{
    key_t key;
    int semid;
    struct sembuf sbuf = {0, -1, IPC_NOWAIT};
    union semun semopts;

    if ((key = ftok("/home/xzwb/1.c", 'a')) == -1) {
        perror("ftok error\n");
        exit(1);
    }
    // 设置信号集
    if ((semid = semget(key, 1, IPC_CREAT|IPC_EXCL)) == -1) {
        perror("semget error\n");
        exit(1);
    }
    semopts.val = 5;
    if (semctl(semid, 0, SETVAL, semopts) == -1) {
        perror("semctl error\n");
        exit(1);
    }

    if (semop(semid, &sbuf, 1) == -1) {
        perror("error\n");
        exit(1);
    }
    sleep(3);

    return 0;
}
