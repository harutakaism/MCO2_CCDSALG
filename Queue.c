#include "Queue.h"

void CreateQ(struct Queue *Q)
{
    //Q = NULL;
    Q->head = 0; //Initialize value of top 上側のすちの初期値
    Q->tail = 0; //Initialize value of bottom 下側のすちの初期値
}

int QueueEmpty(struct Queue *Q)
{
    if(Q->head == Q->tail)
    {
        return 1; //True　真
    }
    else
    {
        return 0; //False ぎ
    }
}

int QueueFull(struct Queue *Q)
{
    if(Q->head == (Q->tail + 1) % MAX_NUM)
    {
        return 1; //True 真
    }
    else
    {
        return 0; //False ぎ
    }
}
void Enqueue(struct Queue *Q, char x[])
{
    if(QueueFull(Q) == 0) //If not full　スタックが満杯で無い場合
    {
        strcpy(Q->QueueMember[Q->tail], x);
        Q->tail++;
    }
    
}

void Dequeue(struct Queue *Q)
{
    if(QueueEmpty(Q) == 0) //If not Empty　スタックが空でない場合
    {
        Q->head++;
    }
    
}

char *QueueHead(struct Queue *Q)
{
    if (QueueEmpty(Q))
    {
        return NULL;
    }

    return Q->QueueMember[Q->head];
}

char *QueueTail(struct Queue *Q)
{
     if (QueueEmpty(Q))
    {
        return NULL;
    }
    return Q->QueueMember[Q->tail - 1];
}
