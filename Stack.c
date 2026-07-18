#include "Stack.h"


void CreateS(struct Stack *S)
{
    //S = NULL;
    S->top = 0; //Initialize value of top 上側のすちの初期値
}

int StackEmpty(struct Stack *S)
{
    if(S->top == 0)
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
    if(S->top == MAX_NUM)
    {
        return 1; //True 真
    }
    else
    {
        return 0; //False ぎ
    }
}

void Push(struct Stack *S, char x[])
{
    if(!StackFull(S))
    {
        strcpy(S->StackMember[S->top], x);
        S->top++;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

void Pop(struct Stack *S)
{
    if(StackEmpty(S) == 0) //If not Empty　スタックが空でない場合
    {
        //S->StackMember[S->top] = '\0';
        S->top--;
    }
    else
    {
        printf("Element not added: Stack Underflow\n");
        printf("要素を追加できませんでした：スタックアンダーフロー\n");
        //NOTE: Can remove the else statements if unnecessary
    }
}

char *Top(struct Stack *S)
{
    if(StackEmpty(S) == 0)
    {
        return S->StackMember[S->top - 1];
    }
    else
    {
        return NULL;
    }
}
