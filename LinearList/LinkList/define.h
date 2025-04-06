#ifndef __DEFINE_H
#define __DEFINE_H
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

#define SQLMAXSIZE 100
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

Status InitList(LinkList *L);
Status GetElem(LinkList L, int i, ElemType *e);
LNode *LocateElem(LinkList L, ElemType e);
int LocateElemIndex(LinkList L, ElemType e);
Status ListInsert(LinkList *L, int i, ElemType e);
Status ListDelete(LinkList *L, int i, ElemType *e);
int ListEmpty(LinkList L);
Status DestroyList(LinkList *L);
Status ClearList(LinkList *L);
int ListLength(LinkList L);
void CreateListHead(LinkList *L, int n);
void CreateListTail(LinkList *L, int n);
#endif

// Define the sequential list
