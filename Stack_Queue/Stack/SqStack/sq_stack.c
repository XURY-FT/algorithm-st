#include "define.h"
#include <stdio.h>
#include <stdlib.h>

Status InitStack(SqStack *S)
{
    S->base = (SElemType *)malloc(SQSMAXSIZE * sizeof(SElemType));
    if (!S->base)
        exit(OVERFLOW);
    S->top = S->base;
    S->stacksize = SQSMAXSIZE;
    return OK;
}

Status Push(SqStack *S, SElemType e)
{
    if (S->top - S->base == SQSMAXSIZE)
        return ERROR;
    *S->top++ = e;
    return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
    if (S->top == S->base)
        return ERROR;
    *e = *--S->top;
    return OK;
}

SElemType GetTop(SqStack S)
{
    if (S.top != S.base)
        return *(S.top - 1);
    else
        return OVERFLOW;
}

Status StackEmpty(SqStack S)
{
    if (S.top == S.base)
        return TRUE;
    else
        return FALSE;
}
int StackLength(SqStack S)
{
    return S.top - S.base;
}
Status ClearStack(SqStack *S)
{
    if (S->base)
        S->top = S->base;
    return OK;
}
Status DestroyStack(SqStack *S)
{
    if (S->base)
    {
        free(S->base);
        S->stacksize = 0;
        S->base = S->top = NULL;
    }
    return OK;
}