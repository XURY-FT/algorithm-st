#ifndef __DEFINE_H
#define __DEFINE_H
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

#define SQQMAXSIZE 10

typedef int QElemType;
typedef struct
{
    QElemType *base; // base pointer
    int front;       // head pointer
    int rear;        // tail pointer
} SqQueue;

Status InitQueue(SqQueue *Q);
Status DestroyQueue(SqQueue *Q);
Status ClearQueue(SqQueue *Q);
Status QueueEmpty(SqQueue Q);
int QueueLength(SqQueue Q);
QElemType GetHead(SqQueue Q);
Status EnQueue(SqQueue *Q, QElemType e);
Status DeQueue(SqQueue *Q, QElemType *e);
Status QueueTraverse(SqQueue Q, Status (*visit)(QElemType));
#endif
