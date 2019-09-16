/*创建一个带头结点的链表，并遍历该链表*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node
{
    int id;
    struct Node *next;
}Node;

void list(Node *head);

int main()
{

    // 头结点
    Node *head, *p, *q;
    
    p = (Node *)malloc(sizeof(Node)); 
    if(p == NULL) perror("create p fail.");

    head = p;

    // 尾插法
    for(int i = 0; i < 3; i++)
    {
        q = (Node *)malloc(sizeof(Node));
        if(q == NULL) perror("create q fail.");

        q->id = i;
        q->next = NULL;

        p->next = q;
        p = q;
    }

    list(head);

    if(head != NULL) { free(head); head = NULL;}
    if(p != NULL) { free(p); p = NULL;}

    return 0;
}

void list(Node *head)
{

    if(head == NULL)
        return;

    Node *p = head->next;

    while(p != NULL)
    {
        printf("id = %d\n", p->id);
        p = p->next;
    }
}
