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
typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *next;
    struct DuLNode *prior;

} DuLNode, *DuLinkList;

void InitList(DuLinkList *L);
DuLNode *GetElem(DuLinkList L, int i);
void CreateListHead(DuLinkList *L, int n);
void CreateListTail(DuLinkList *L, int n);
Status ListInsert(DuLinkList *L, int i, ElemType e);
Status ListDelete(DuLinkList *L, int i, ElemType *e);

#endif

// Define the sequential list
