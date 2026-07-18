//The following libraries are the only one allowed
//利用がされたライブラリーのみ
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//NOTE: change capacity of stack here
//ここで最大数を変更してください
#define MAX_NUM 256

//Queue Library キュー
struct Queue
{
    char QueueMember[MAX_NUM][MAX_NUM];  //data type can be changed　変更これください
    int head;                   //do not change 変更しないでください
    int tail;                   //do not change 変更しないでください
};

void CreateQ(struct Queue *Q);
int QueueEmpty(struct Queue *Q);
int QueueFull(struct Queue *Q);
void Enqueue(struct Queue *Q, char x[]);
void Dequeue(struct Queue *Q);
char *QueueHead(struct Queue *Q);
char *QueueTail(struct Queue *Q);
