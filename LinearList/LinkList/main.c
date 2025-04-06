#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "link_list.c"

int main()
{
    LinkList L;
    InitList(&L);
    int n;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    CreateListHead(&L, n);
    printf("List created with %d elements.\n", n);
    LinkList p = L->next;
    printf("List elements: ");
    while (p)
    {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
    int i, e;
    printf("Enter the position to insert an element: ");
    scanf("%d", &i);
    printf("Enter the element to insert: ");
    scanf("%d", &e);
    if (ListInsert(&L, i, e) == OK)
        printf("Element %d inserted at position %d.\n", e, i);
    else
        printf("Insertion failed.\n");
    printf("List elements after insertion: ");
    p = L->next;
    while (p)
    {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
    printf("Enter the position to delete an element: ");
    scanf("%d", &i);
    if (ListDelete(&L, i, &e) == OK)
        printf("Element %d deleted from position %d.\n", e, i);
    else
        printf("Deletion failed.\n");
    p = L->next;
    while (p)
    {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
    printf("Enter the position to get an element: ");
    scanf("%d", &i);
    if (GetElem(L, i, &e) == OK)
        printf("Element at position %d is %d.\n", i, e);
    else
        printf("Failed to get element at position %d.\n", i);
    printf("Enter an element to find: ");
    int elem;
    scanf("%d", &elem);
    LNode *pos = LocateElem(L, elem);
    if (pos != NULL)
        printf("Element %d found at position %p\n", elem, pos);
    else
        printf("Element %d not found in the list.\n", elem);
    printf("Enter an element to find its index: ");
    scanf("%d", &elem);
    int index = LocateElemIndex(L, elem);
    if (index != 0)
        printf("Element %d found at index %d\n", elem, index);
    else
        printf("Element %d not found in the list.\n", elem);
    printf("Is the list empty? %s\n", ListEmpty(L) ? "Yes" : "No");
    printf("Clearing the list...\n");
    ClearList(&L);
    printf("Is the list empty? %s\n", ListEmpty(L) ? "Yes" : "No");
    printf("Destroying the list...\n");
    DestroyList(&L);
    printf("Is the list empty? %s\n", ListEmpty(L) ? "Yes" : "No");
    printf("List length: %d\n", ListLength(L));
    return 0;
}
