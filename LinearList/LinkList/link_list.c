#include "define.h"
#include <stddef.h>

Status InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));
    if (!*L)
        exit(OVERFLOW);
    (*L)->next = NULL;
    return OK;
}

int ListEmpty(LinkList L)
{
    if (L->next)
        return FALSE;
    return TRUE;
}

Status DestroyList(LinkList *L)
{
    if (!*L)
        return ERROR;
    LinkList p = *L;
    while (p)
    {
        LinkList q = p;
        p = p->next;
        free(q);
        q = NULL;
    }
    *L = NULL;
    return OK;
}

Status ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

int ListLength(LinkList L)
{
    LinkList p;
    p = L->next;
    int i = 0;
    while (p)
    {
        p = p->next;
        i++;
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType *e)
{
    LinkList p;
    p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}

LNode *LocateElem(LinkList L, ElemType e)
{
    LinkList p;
    p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    if (!p)
        return NULL;
    return p;
}

int LocateElemIndex(LinkList L, ElemType e)
{
    LinkList p;
    p = L->next;
    int i = 1;
    while (p && p->data != e)
    {
        p = p->next;
        i++;
    }
    if (!p)
        return 0;
    return i;
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
    LinkList p;
    p = *L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return ERROR;
    LinkList s = (LinkList)malloc(sizeof(LNode));
    if (!s)
        exit(OVERFLOW);
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
    LinkList p;
    p = *L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i - 1)
        return ERROR;
    LinkList q = p->next;
    if (!q)
        return ERROR;
    p->next = q->next;
    *e = q->data;
    free(q);
    q = NULL;
    return OK;
}

void CreateListHead(LinkList *L, int n)
{
    for (int i = 0; i < n; i++)
    {

        LinkList s = (LinkList)malloc(sizeof(LNode));
        int data;
        printf("Please input the data of the node %d: ", i + 1);
        scanf("%d", &data);
        if (!s)
            exit(OVERFLOW);
        s->data = data;
        s->next = (*L)->next;
        (*L)->next = s;
    }
}
void CreateListTail(LinkList *L, int n)
{
    LinkList p = *L;
    for (int i = 0; i < n; i++)
    {
        LinkList s = (LinkList)malloc(sizeof(LNode));
        int data;
        printf("Please input the data of the node %d: ", i + 1);
        scanf("%d", &data);
        if (!s)
            exit(OVERFLOW);
        s->data = data;
        s->next = NULL;
        p->next = s;
        p = s;
    }
}