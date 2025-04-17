#include <stdio.h>
#include "define.h"
#include "link_queue.c"
#include <stdlib.h>

int main()
{
    LinkQueue Q;
    InitQueue(&Q);
    printf("Queue initialized.\n");
    for (int i = 0; i < 10; i++)
    {
        EnQueue(&Q, i);
    }
    printf("Queue length: \n");
    printf("Queue length: %d\n", QueueLength(Q));

    // Check if the queue is empty before accessing the head
    if (QueueLength(Q) > 0)
    {
        printf("Queue head: %d\n", GetHead(Q));
    }
    else
    {
        printf("Queue is empty, no head to display.\n");
    }

    QElementype e;
    while (DeQueue(&Q, &e) == OK)
    {
        printf("Dequeued: %d\n", e);
    }
    printf("Queue length after dequeue: %d\n", QueueLength(Q));

    // Ensure DestroyQueue works safely even if the queue is empty
    DestroyQueue(&Q);
    printf("Queue destroyed.\n");
    return 0;
}
