//The following libraries are the only one allowed
//利用がされたライブラリーのみ
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Heap.c"

//Heap Library
struct Heap
{
    int pHeapArray[256];        //do not change 変更しないでください
    int nCursize;          //data type can be changed　変更これください
    int nMaxcapacity;      //data type can be changed　変更これください
};

int Parent(int Index);
int LeftChild(int Index);
int RightChild(int Index);
void Swap(int *A, int *B);
void HeapUp(struct Heap *pHeap, int nIndexNumber);
void MaxHeapify(struct  Heap *pHeap, int IndexAt
void BuildMaxHeap(struct Heap *pHeap, int NumeroNoIndex);
void HeapSort(struct Heap *pHeap, int Ueda);
int HeapMaximum(struct Heap pHeap);
void HeapInsert(struct Heap *pHeap, int Index, int Numbero);
