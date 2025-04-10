#include <stdio.h>
#include "define.h"
#include <stdlib.h>

Status InitQueue(SqQueue *Q)
{
    Q->base = (QElemType *)malloc(SQQMAXSIZE * sizeof(QElemType));
    if (!Q->base)
    {
        exit(OVERFLOW);
    }
    Q->front = 0;
    Q->rear = 0;
    return OK;
}
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + SQQMAXSIZE) % SQQMAXSIZE;
}
Status EnQueue(SqQueue *Q, QElemType e)
{
    if ((Q->rear + 1) % SQQMAXSIZE == Q->front)
        return ERROR;
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % SQQMAXSIZE;
    return OK;
}
Status DeQueue(SqQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear)
        return ERROR;
    *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % SQQMAXSIZE;
    return OK;
}
QElemType GetHead(SqQueue Q)
{
    if (Q.front == Q.rear)
        return ERROR;
    return Q.base[Q.front];
}