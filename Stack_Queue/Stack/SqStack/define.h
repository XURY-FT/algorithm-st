#ifndef __DEFINE_H
#define __DEFINE_H
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

#define SQSMAXSIZE 100
typedef int SElemType;

typedef struct SqStack
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

Status InitStack(SqStack *S);
Status Push(SqStack *S, SElemType e);
Status Pop(SqStack *S, SElemType *e);
SElemType GetTop(SqStack S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status ClearStack(SqStack *S);
Status DestroyStack(SqStack *S);

#endif
