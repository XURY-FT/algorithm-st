#ifndef __DEFINE_H
#define __DEFINE_H
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

#define LINKSMAXSIZE 100

typedef int SElemType;

typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

Status InitStack(LinkStack *S);
Status Push(LinkStack *S, SElemType e);
Status Pop(LinkStack *S, SElemType *e);
SElemType GetTop(LinkStack S);
Status StackEmpty(LinkStack S);
int StackLength(LinkStack S);
Status ClearStack(LinkStack *S);
Status DestroyStack(LinkStack *S);

#endif
