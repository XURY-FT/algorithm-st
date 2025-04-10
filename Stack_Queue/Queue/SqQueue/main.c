#include <stdio.h>
#include "define.h"
#include "sq_queue.c"
int main()
{
    SqQueue Q;
    QElemType e;
    InitQueue(&Q);
    for (int i = 0; i < 9; i++)
    {
        EnQueue(&Q, i);
    }
    printf("Queue head: %d\n", GetHead(Q));
    printf("Queue elements: ");
    printf("Queue length: %d\n", QueueLength(Q));
    int length = QueueLength(Q);
    for (int i = 0; i < length; i++)
    {
        DeQueue(&Q, &e);
        printf("%d ", e);
    }
    printf("\n");
    printf("Queue length after dequeue: %d\n", QueueLength(Q));

    return 0;
}
