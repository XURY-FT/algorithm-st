#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "link_stack.c"
int main()
{
    LinkStack S;
    SElemType e;
    InitStack(&S);
    for (int i = 0; i < 10; i++)
    {
        Push(&S, i);
    }
    printf("Stack length: %d\n", StackLength(S));
    printf("Top element: %d\n", GetTop(S));
    while (!StackEmpty(S))
    {
        Pop(&S, &e);
        printf("Popped element: %d\n", e);
    }
    printf("Stack length after popping: %d\n", StackLength(S));
    for (int i = 0; i < 10; i++)
    {
        Push(&S, i);
    }
    printf("Stack length: %d\n", StackLength(S));
    printf("Top element: %d\n", GetTop(S));
    ClearStack(&S);
    printf("Stack length after clearing: %d\n", StackLength(S));
    DestroyStack(&S);
    printf("Stack destroyed.\n");
    printf("Stack length after destroying: %d\n", StackLength(S));
    return 0;
}