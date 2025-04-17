#include "define.h"
#include <stdio.h>
#include <stdlib.h>

Status InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front)
        exit(OVERFLOW);
    Q->front->next = NULL;
    return OK;
}

Status DestroyQueue(LinkQueue *Q)
{
    QueuePtr p;
    while (Q->front)
    {
        p = Q->front->next;
        free(Q->front);
        Q->front = p;
    }
    Q->rear = NULL;
    return OK;
}

Status EnQueue(LinkQueue *Q, QElementype e)
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

Status DeQueue(LinkQueue *Q, QElementype *e)
{
    if (Q->front == Q->rear)
        return ERROR;

    QueuePtr p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (p == Q->rear)
        Q->rear = Q->front;
    free(p);
    return OK;
}

QElementype GetHead(LinkQueue Q)
{
    if (Q.front != Q.rear)
        return Q.front->next->data;
    return ERROR;
}
int QueueLength(LinkQueue Q)
{
    int length = 0;
    QueuePtr p = Q.front->next;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}