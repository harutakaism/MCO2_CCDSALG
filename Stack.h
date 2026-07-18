//The following libraries are the only one allowed
//利用がされたライブラリーのみ
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM 256

struct Stack
{
    char StackMember[MAX_NUM][MAX_NUM];
    int top;
};

void CreateS(struct Stack *S);
int StackEmpty(struct Stack *S);
int StackFull(struct Stack *S);
void Push(struct Stack *S, char x[]);
void Pop(struct Stack *S);
char *Top(struct Stack *S);
