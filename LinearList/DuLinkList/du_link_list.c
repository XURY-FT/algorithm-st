#include "define.h"
#include <stdio.h>

/*待优化*/

void InitList(DuLinkList *L)
{
    *L = (DuLinkList)malloc(sizeof(DuLNode));
    if (!*L)
        exit(OVERFLOW);
    (*L)->next = NULL;
    (*L)->prior = NULL;
}

DuLNode *GetElem(DuLinkList L, int i)
{
    DuLNode *p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (j > i || !p)
        return NULL;
    return p;
}
Status ListInsert(DuLinkList *L, int i, ElemType e)
{
    DuLinkList p = *L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p)
        return ERROR;
    DuLNode *s = (DuLNode *)malloc(sizeof(DuLNode));
    if (!s)
        exit(OVERFLOW);
    s->data = e;
    // Insert after p (covers i == 1 and appending cases naturally)
    s->prior = p;
    s->next = p->next;
    if (p->next)
    {
        p->next->prior = s;
    }
    p->next = s;
    return OK;
}

Status ListDelete(DuLinkList *L, int i, ElemType *e)
{
    DuLNode *p;
    if (!(p = GetElem(*L, i)))
        return ERROR;
    *e = p->data;
    if (i == 1)
    {
        (*L)->next = p->next;
        if (p->next)             // 检查是否有新首节点
            p->next->prior = *L; // 新首节点的 prior 指向虚拟头节点
        free(p);
        return OK;
    }
    if (!p->next)
    {
        p->prior->next = NULL;
        free(p);
        return OK;
    }

    p->prior->next = p->next;
    p->next->prior = p->prior;

    free(p);
    return OK;
}

void CreateListHead(DuLinkList *L, int n)
{
    DuLinkList p = *L;
    for (int i = 0; i < n; i++)
    {
        DuLNode *s = (DuLNode *)malloc(sizeof(DuLNode));
        if (!s)
            exit(OVERFLOW);
        int data;
        printf("Please input the data of the node %d: ", i + 1);
        scanf("%d", &data);
        s->data = data;
        s->next = p->next;
        if (p->next)
            p->next->prior = s;
        s->prior = p;
        p->next = s;
    }
}
void CreateListTail(DuLinkList *L, int n)
{
    DuLinkList p = *L;
    for (int i = 0; i < n; i++)
    {
        DuLNode *s = (DuLNode *)malloc(sizeof(DuLNode));
        if (!s)
            exit(OVERFLOW);
        int data;
        printf("Please input the data of the node %d: ", i + 1);
        scanf("%d", &data);
        s->data = data;
        s->next = NULL;
        s->prior = p;
        p->next = s;
        p = s;
    }
}