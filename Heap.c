//The following libraries are the only one allowed
//利用がされたライブラリーのみ
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//Heap Library
struct Heap
{
    int *pHeapArray;        //do not change 変更しないでください
    int nCursize;          //data type can be changed　変更これください
    int nMaxcapacity;      //data type can be changed　変更これください
};

void Swap(int *A, int *B)
{
    int temp;
    temp = *A;
    *A = *B;
    *B = temp;
}
/* Let n = index of a specific element
 * Parent of n = (n - 1) / 2
 * Left Child of n = (n*2) + 1
 * Right Child of n = (n*2) + 2
 */
void HeapUp(struct Heap *pHeap, int nIndexNumber)
{
    int nParent;
    while (nIndexNumber != 0)
    {
        nParent = (nIndexNumber - 1) / 2; //
        if(pHeap->pHeapArray[nIndexNumber] > pHeap->pHeapArray[nParent])
        {
            Swap(&pHeap->pHeapArray[nIndexNumber],&pHeap->pHeapArray[nParent]);
            nIndexNumber = nParent;
        }
    }
}
