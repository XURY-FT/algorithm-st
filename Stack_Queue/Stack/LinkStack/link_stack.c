#include "define.h"
#include <stdio.h>
#include <stdlib.h>

Status InitStack(LinkStack *S)
{
    *S = (LinkStack)malloc(sizeof(StackNode));
    if (!*S)
        exit(OVERFLOW);
    (*S)->next = NULL;
}
Status Push(LinkStack *S, SElemType e)
{
    StackNode *s = (StackNode *)malloc(sizeof(StackNode));
    if (!s)
        exit(OVERFLOW);
    s->data = e;
    s->next = *S;
    *S = s;
    return OK;
}

Status Pop(LinkStack *S, SElemType *e)
{
    if (*S == NULL)
        return ERROR;
    *e = (*S)->data;
    StackNode *p = *S;
    *S = (*S)->next;
    free(p);
    return OK;
}

SElemType GetTop(LinkStack S)
{
    if (S == NULL)
        return ERROR;
    return S->data;
}
Status StackEmpty(LinkStack S)
{
    if (S == NULL)
        return TRUE;
    return FALSE;
}
int StackLength(LinkStack S)
{
    int i = 0;
    while (S)
    {
        i++;
        S = S->next;
    }
    return i;
}
Status ClearStack(LinkStack *S)
{
    StackNode *p;
    while (*S)
    {
        p = *S;
        *S = (*S)->next;
        free(p);
    }
    return OK;
}
Status DestroyStack(LinkStack *S)
{
    ClearStack(S);
    free(*S);
    *S = NULL;
    return OK;
}