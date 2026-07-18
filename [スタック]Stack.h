//The following libraries are the only one allowed
//利用がされたライブラリーのみ
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//NOTE: change capacity of stack here
//ここで最大数を変更してください
#define MAX_NUM 100

//Stack Library スタク
struct Stack
{
    char StackMember[MAX_NUM];  //data type can be changed　変更これください
    int top;                    //do not change 変更しないでください
};

void Create(struct Stack *S)
{
    //S = NULL;
    S->top = 0; //Initialize value of top 上側のすちの初期値
}

int StackEmpty(struct Stack *S)
{
    if(S->top == 0 && S->StackMember[0] == '\0')
    {
        return 1; //True　真
    }
    else
    {
        return 0; //False ぎ
    }
}

int StackFull(struct Stack *S)
{
    if(S->top == MAX_NUM - 1)
    {
        return 1; //True 真
    }
    else
    {
        return 0; //False ぎ
    }
}
void Push(struct Stack *S, char x)
{
    if(StackFull(S) == 0) //If not full　スタックが満杯で無い場合
    {
        S->StackMember[S->top] = x;
        S->top++;
    }
    else
    {
        printf("Element not added: Stack Overflow\n");
        printf("要素を追加できませんでした：スタックオーバフロー\n");
        //NOTE: Can remove the else statements if unnecessary
    }
}

void Pop(struct Stack *S)
{
    if(StackEmpty(S) == 0) //If not Empty　スタックが空でない場合
    {
        S->StackMember[S->top] = '\0';
        S->top--;
    }
    else
    {
        printf("Element not added: Stack Underflow\n");
        printf("要素を追加できませんでした：スタックアンダーフロー\n");
        //NOTE: Can remove the else statements if unnecessary
    }
}

char Top(struct Stack *S)
{
    return S->StackMember[S->top];
}