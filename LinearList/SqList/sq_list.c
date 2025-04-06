#include "define.h"
#include <stddef.h>

Status InitList(SqList *L)
{
    L->base = (ElemType *)malloc(SQLMAXSIZE * sizeof(ElemType));
    if (!L->base)
        exit(OVERFLOW);
    L->length = 0;
    return OK;
}
// 获取第i个元素的值
int GetElem(SqList L, int i, ElemType *e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    *e = L.base[i - 1];
    return OK;
}
int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.base[i] == e)
            return i + 1;
    }
    return 0;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
    if (i < 1 || i > L->length + 1)
        return ERROR;
    if (L->length == SQLMAXSIZE)
        return ERROR;
    for (int j = L->length; j >= i - 1; j--)
    {
        L->base[j + 1] = L->base[j];
    }
    L->base[i - 1] = e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L, int i)
{
    if (i < 1 || i > L->length)
        return ERROR;
    for (int j = i; j < L->length; j++)
    {
        L->base[j - 1] = L->base[j];
    }
    L->length--;
    return OK;
}

void DestroyList(SqList *L)
{
    if (L->base)
    {
        free(L->base);
        L->base = NULL;
    }
    L->length = 0;
}
void ClearList(SqList *L)
{
    L->length = 0;
}
int GetLength(SqList L)
{
    return L.length;
}
int isEmpty(SqList L)
{
    return L.length == 0;
}