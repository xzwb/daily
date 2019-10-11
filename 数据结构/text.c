#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
    long num;
    char class[50];
    char name[20];
    struct Student *next;
} Student;

Student *creat()
{
    Student *head = NULL;
    Student *p;
    Student *p1;
    p = malloc(sizeof(Student));
    int i = 0;
    while (i++ < 3) {
        printf("学号:\n");
        scanf("%d", &p->num);
        printf("班级:\n");
        scanf("%s", p->class);
        printf("姓名:\n");
        scanf("%s", p->name);
        if (head == NULL) {
            head = p;
        } else {
            p1->next = p;
        }
        p1 = p;
        p = malloc(sizeof(Student));
    }
    p1->next = NULL;

    return head;
}

Student *serch(Student *head, const char *name)
{
    Student *p = head;
    while (p) {
        if (strcmp(p->name, name) == 0) {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

Student *serch_num(Student *head, int num) 
{
    Student *p = head;
    for (int i = 0; i != num; ++i) {
        p = p->next;
    }
    if (p != NULL) {
        return p;
    } else {
        return NULL;
    }
}

Student *add(Student *node, Student *head, int num)
{
    Student *p = head;
    Student *p1;
    for (int i = 0; i < num-1; i++) {
        p = p->next;
    }
    if (p == head) {
        head = node;
        node->next = p;
    } else if (p->next == NULL) {
        p->next = node;
        node->next = NULL;
    } else{
        p1 = p->next;
        p->next = node;
        node->next = p1;
    }

    return head;
}

Student *delete(int num, Student *head) 
{
    int i = 0;
    Student *p = head;
    Student *p1;
    while (i != num-1) {
        p1 = p;
        p = p->next; 
        i++;
    }
    if (p == head) {
        head = p->next;
        free(p);
    } else if (p->next == NULL) {
        p1->next = NULL;
        free(p);
    } else {
        p1->next = p->next;
        free(p);
    }

    return head;
}

void print(Student *head) 
{
    Student *p = head;
    while (p) {
        printf("%d\t%s\t%s\n", p->num, p->class, p->name);
        p = p->next;
    }
}

int main()
{
    Student *head;
    Student *node;
    node = malloc(sizeof(Student));
    node->num = 1518;
    strcpy(node->class, "电子1801");
    strcpy(node->name, "杨懿凡");
    head = creat();
  //  Student *result;
 //   result = serch(head, "yyf");
 //   printf("%d\n", result->num);
//    head = delete(1, head);
    add(node, head, 2);
    print(head);
}
