/* 链表的插入和删除 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int id;
    struct Node *next;
} Node;

// a 的后面插入 b
void insertNode(Node *head, int a, int b);
// 删除 id = a 的节点
void deleteNode(Node *Node, int a);
// 创建一个带有头结点的链表
void createList(Node *head);
// 遍历链表
void showList(Node *head);
// 释放链表
void freeList(Node *head);

int main()
{
    Node *head = NULL;
    head = (Node *)malloc(sizeof(Node));
    if (head == NULL)
    {
        perror("head is NULL.");
    }

    createList(head);
    showList(head);

    printf("----- insert node -----\n");

    insertNode(head, 1, 5);
    showList(head);

    printf("----- delete node -----\n");

    deleteNode(head, 2);
    showList(head);

    if (head != NULL)
    {
        freeList(head);
    }

    return 0;
}

void insertNode(Node *head, int a, int b)
{
    if (head == NULL)
        return;

    Node *p = head->next;

    Node *q = (Node *)malloc(sizeof(Node));
    q->id = b;

    while (p != NULL)
    {
        if (p->id == a)
        {
            q->next = p->next;
            p->next = q;
            return;
        }
        p = p->next;
    }
}

void deleteNode(Node *head, int a)
{
    if (head == NULL)
        return;

    Node *p = head;

    while (p != NULL)
    {
        if (p->next->id == a)
        {
            p->next = p->next->next;
            return;
        }
        p = p->next;
    }
}

void createList(Node *head)
{
    if (head == NULL)
        return;

    Node *p, *q = NULL;
    p = head;

    for (int i = 0; i < 3; i++)
    {
        q = (Node *)malloc(sizeof(Node));
        q->id = i;
        p->next = q;
        p = q;
    }
}

void showList(Node *head)
{

    if (head == NULL)
        return;

    Node *p = head->next;

    while (p != NULL)
    {
        printf("id = %d\n", p->id);
        p = p->next;
    }
}

void freeList(Node *head)
{
    if (head == NULL)
        return;

    Node *p = NULL;

    while (head != NULL)
    {
        p = head;
        head = head->next;
        free(p);
        p = NULL;
    }
}