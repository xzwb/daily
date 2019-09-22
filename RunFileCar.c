#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int pid;
    while (1) {
       pid = fork();
       if (pid == 0) {
           execlp("sl","sl",NULL);
           exit(0);
       }
       wait(&pid);
    }

    return 0;
}
