#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "sq_list.c"

int main()
{
    SqList L;
    InitList(&L);
    printf("%d\n", L.length);
    ListInsert(&L, 1, 2);
    ListInsert(&L, 2, 3);
    ListInsert(&L, 3, 4);

    for (int i = 1; i <= L.length; i++)
    {
        int e;
        GetElem(L, i, &e);
        printf("%d\n", e);
    }
    int j = LocateElem(L, 3);
    printf("%d\n", j);
    ListDelete(&L, 2);
    for (int i = 1; i <= L.length; i++)
    {
        int e;
        GetElem(L, i, &e);
        printf("%d\n", e);
    }
    int isEmp = isEmpty(L);
    printf("%d empty\n", isEmp);
    ClearList(&L);
    isEmp = isEmpty(L);
    printf("%d empty\n", isEmp);
    printf("%d\n", L.length);
    ListInsert(&L, 1, 5);
    ListInsert(&L, 2, 6);
    ListInsert(&L, 3, 7);
    for (int i = 1; i <= L.length; i++)
    {
        int e;
        GetElem(L, i, &e);
        printf("%d\n", e);
    }
    DestroyList(&L);
    printf("%d\n", L.length);

    return 0;
}
