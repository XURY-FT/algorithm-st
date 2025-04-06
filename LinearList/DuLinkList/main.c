#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "du_link_list.c"

int main()
{
    DuLinkList L;
    InitList(&L);
    int n;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    CreateListHead(&L, n);
    printf("List after head insertion:\n");
    for (int i = 1; i <= n; i++)
    {
        DuLNode *p = GetElem(L, i);
        printf("%d ", p->data);
    }
    printf("\n");
    /** 创建只能调用一次 不能 CreateListHead CreateListTail 同时调用*/
    // printf("Enter the number of elements to insert at the tail: ");
    // scanf("%d", &n);
    // CreateListTail(&L, n);
    // printf("List after tail insertion:\n");
    // for (int i = 1; i <= 2 * n; i++)
    // {
    //     DuLNode *p = GetElem(L, i);
    //     printf("%d ", p->data);
    // }
    // printf("\n");

    int i;
    printf("Enter the position to insert an element: ");
    scanf("%d", &i);
    int e;
    printf("Enter the element to insert: ");
    scanf("%d", &e);
    if (ListInsert(&L, i, e) == OK)
    {
        printf("List after insertion:\n");
        for (int j = 1; j <= n + 1; j++)
        {
            DuLNode *p = GetElem(L, j);
            printf("%d ", p->data);
        }
        printf("\n");
    }
    else
    {
        printf("Insertion failed.\n");
    }
    printf("Enter the position to delete an element: ");
    scanf("%d", &i);
    if (ListDelete(&L, i, &e) == OK)
    {
        printf("List after deletion:\n");
        for (int j = 1; j <= n; j++)
        {
            DuLNode *p = GetElem(L, j);
            printf("%d ", p->data);
        }
        printf("\nDeleted element: %d\n", e);
    }
    else
    {
        printf("Deletion failed.\n");
    }
    return 0;
}
