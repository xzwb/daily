#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bank.h"
#include "Call.h"
#include "Queue.h"

// 全局变量自动赋值为0,用来叫号的号
int number;

int main() 
{
    // 初始化用户队列
    Queue *queue = create();
    // 用来做选择
    int choose;
    // 空柜台
    int table;
    char password[100];
    while (1) {
        menu();
        scanf("%d", &choose);
        switch (choose) {
            case 1:
                    printf("您的号码为%d!!\n", give(queue, number++, 0));
                    break;
                    
            case 2:
                    printf("您的号码为%d!!\n", give(queue, number++, 1));
                    break;
            case 3:
                    printf("请输入现在空着的柜台:\n");
                    scanf("%d", &table);
                    call(queue, table);
                    break;
            case 4:
                    printf("输入密码:");
                    scanf("%s", password);
                    if (strcmp(password, "123456") == 0) {
                        release(queue);
                        return 0;
                    } else {
                        printf("密码错误!!");
                    }
                    break;
            default:break;
        }
        getchar();
        printf("按下回车键继续.......");
        getchar();
    }

    return 0;
} 
