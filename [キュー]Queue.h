//The following libraries are the only one allowed
//利用がされたライブラリーのみ
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//NOTE: change capacity of stack here
//ここで最大数を変更してください
#define MAX_NUM 100

//Queue Library キュー
struct Queue
{
    char QueueMember[MAX_NUM];  //data type can be changed　変更これください
    int head;                   //do not change 変更しないでください
    int tail;                   //do not change 変更しないでください
};

void Create(struct Queue *Q)
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
void Enqueue(struct Queue *Q, char x)
{
    if(QueueFull(Q) == 0) //If not full　スタックが満杯で無い場合
    {
        Q->QueueMember[Q->tail] = x;
        Q->tail++;
    }
    else
    {
        printf("Element not added: Queue Overflow\n");
        printf("要素を追加できませんでした：キューオーバフロー\n");
        //NOTE: Can remove the else statements if unnecessary
    }
}

void Dequeue(struct Queue *Q)
{
    if(QueueEmpty(Q) == 0) //If not Empty　スタックが空でない場合
    {
        Q->head++;
    }
    else
    {
        printf("Element not removed: Queue Underflow\n");
        printf("要素を追加できませんでした：キューアンダーフロー\n");
        //NOTE: Can remove the else statements if unnecessary
    }
}

char QueueHead(struct Queue *Q)
{
    return Q->QueueMember[Q->head];
}

char QueueTail(struct Queue *Q)
{
    return Q->QueueMember[Q->tail];
}