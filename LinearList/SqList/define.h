#ifndef __DEFINE_H
#define __DEFINE_H
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
// Define the sequential list
#define SQLMAXSIZE 100
typedef int ElemType;
typedef struct SqList
{
    ElemType *base;
    int length;
} SqList;

Status InitList(SqList *L);
Status GetElem(SqList L, int i, ElemType *e);
int LocateElem(SqList L, ElemType e);
Status ListInsert(SqList *L, int i, ElemType e);
Status ListDelete(SqList *L, int i);
void DestroyList(SqList *L);
void ClearList(SqList *L);
int GetLength(SqList L);
int isEmpty(SqList L);

#endif