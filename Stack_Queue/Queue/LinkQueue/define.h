#ifndef __DEFINE_H
#define __DEFINE_H
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXQSIZE 100
typedef int Status;
typedef int QElementype;

typedef struct QNode
{
    QElementype data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;
Status InitQueue(LinkQueue *Q);
Status DestroyQueue(LinkQueue *Q);
Status EnQueue(LinkQueue *Q, QElementype e);
Status DeQueue(LinkQueue *Q, QElementype *e);
QElementype GetHead(LinkQueue Q);
int QueueLength(LinkQueue Q);

#endif
