//The following libraries are the only one allowed
//利用がされたライブラリーのみ
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Heap Library
struct Heap
{
    int pHeapArray[256];        //do not change 変更しないでください
    int nCursize;          //data type can be changed　変更これください
    int nMaxcapacity;      //data type can be changed　変更これください
};

int Parent(int Index);
