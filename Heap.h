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

int Parent(int Index)
{
    return(Index - 1)/2;
}
int LeftChild(int Index)
{
    return (Index*2)+1;
}
int RightChild(int Index)
{
    return (Index*2)+2;
}
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
    while (nIndexNumber > 0)
    {
        nParent = (nIndexNumber - 1) / 2; //
        if(pHeap->pHeapArray[nIndexNumber] > pHeap->pHeapArray[nParent])
        {
            Swap(&pHeap->pHeapArray[nIndexNumber],&pHeap->pHeapArray[nParent]);
            nIndexNumber = nParent;
        }
    }
}

void MaxHeapify(struct  Heap *pHeap, int IndexAt)
{
 int Le, Ri, HoogsteVanDijk; //HoogsteVanDijk is Highest Number
 Le = LeftChild(IndexAt); //Left Child
 Ri = RightChild(IndexAt); //Right Child
 if(Le <= pHeap->nCursize && pHeap->pHeapArray[Le] > pHeap->pHeapArray[Ri])
 {
     HoogsteVanDijk = Le;
 }
 else
 {
     HoogsteVanDijk = IndexAt;
 }
 if(Ri <= pHeap->nCursize && pHeap->pHeapArray[Ri] > pHeap->pHeapArray[HoogsteVanDijk])
 {
     HoogsteVanDijk = Ri;
 }
 if(HoogsteVanDijk != IndexAt)
 {
     Swap(&pHeap->pHeapArray[HoogsteVanDijk], &pHeap->pHeapArray[IndexAt]);
     MaxHeapify(pHeap,HoogsteVanDijk);
 }

}
void BuildMaxHeap(struct Heap *pHeap, int NumeroNoIndex)
{
    int i;
    pHeap->nCursize = NumeroNoIndex;
    for(i = NumeroNoIndex/2; i > 1; i++)
    {
        MaxHeapify(pHeap, i);
    }
}
void HeapSort(struct Heap *pHeap, int Ueda)
{
    int i;
    BuildMaxHeap(pHeap, Ueda);
    for(i = Ueda; i > 2; i--)
    {
        Swap(&pHeap->pHeapArray[0],&pHeap->pHeapArray[i]);
        pHeap->nCursize -= 1;
        MaxHeapify(pHeap,0);
    }
}
int HeapMaximum(struct Heap pHeap)
{
    if(pHeap.nCursize < 1)
    {
        printf("for example nothing: ない");
        return -1;
    }
    return pHeap.pHeapArray[0];
}

int HeapExtractMax(struct Heap dHeap)
{
    int maxHiroki;
    maxHiroki = HeapMaximum(dHeap);
    dHeap.pHeapArray[0] = dHeap.pHeapArray[dHeap.nCursize];
    dHeap.nCursize -= 1;
    MaxHeapify(&dHeap,0);
    return maxHiroki;
}
