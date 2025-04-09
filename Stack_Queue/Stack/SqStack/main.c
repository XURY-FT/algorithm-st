#include "define.h"
#include <stdio.h>
#include "sq_stack.c"
int main()
{

        SqStack S;
        InitStack(&S);
        int i;
        for (i = 0; i < 10; i++)
        {
                Push(&S, i);
        }
        printf("Stack length: %d\n", StackLength(S));
        printf("Stack top: %d\n", GetTop(S));
        SElemType e;
        while (!StackEmpty(S))
        {
                Pop(&S, &e);
                printf("Popped element: %d\n", e);
        }
        printf("Stack length after popping: %d\n", StackLength(S));
        for (i = 0; i < 10; i++)
        {
                Push(&S, i);
        };
        printf("Stack length after pushing: %d\n", StackLength(S));
        ClearStack(&S);
        printf("Stack length after clearing: %d\n", StackLength(S));
        DestroyStack(&S);
        printf("Stack destroyed.\n");

        return 0;
}
