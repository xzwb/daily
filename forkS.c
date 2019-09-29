#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid;
    pid = fork();
    if (pid == 0) {
        while (1) {
        
        }
    } else {
        wait(&pid);
    }
}
