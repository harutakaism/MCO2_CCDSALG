#include "GraphTraversals.h"  
 
 int isVisited(char visited[][257],int visitedCount,char *name)
{
    int i;
    for (i=0;i<visitedCount;i++){
        if (strcmp(visited[i], name) == 0)
        {
        return 1; }

        }

    return 0;
}

void depthFirstSearch(GraphTag *graph, char *startName)
{
    struct Stack stack;
    char visited[256][257];
    int visitedCount = 0;

    if (findVertex(graph, startName) == NULL){

        return;
    }

    CreateS(&stack);
    Push(&stack, startName);

    while (!StackEmpty(&stack)){
        char *currentName = Top(&stack);
        VertexNodeTag *currentVertex;
        EdgeNodeTag *currEdge;
        int foundNext = 0;

        if (!isVisited(visited, visitedCount, currentName)){
            strcpy(visited[visitedCount], currentName);
            visitedCount++;
            printf("%s\n", currentName);
        }

        currentVertex = findVertex(graph, currentName);
        currEdge = currentVertex->firstEdge;

        while (currEdge != NULL){
            if (!isVisited(visited, visitedCount, currEdge->dest)){
                Push(&stack, currEdge->dest);
                foundNext = 1;
                break;
            }

            currEdge = currEdge->nextEdge;
        }

        if (!foundNext){
            Pop(&stack);
        }
    }
}

void breadthFirstSearch(GraphTag *graph, char *startName)
{
    struct Queue queue;
    char visited[256][257];
    int visitedCount = 0;

    if (findVertex(graph, startName) == NULL){

        return;
    }

    CreateQ(&queue);

    Enqueue(&queue, startName);

    strcpy(visited[visitedCount], startName);
    visitedCount++;

    while (!QueueEmpty(&queue))
    {
        VertexNodeTag *currVertex = findVertex(graph, QueueHead(&queue));
        EdgeNodeTag *currEdge = currVertex->firstEdge;

        printf("%s\n", QueueHead(&queue));
        Dequeue(&queue);
        

        while(currEdge != NULL)
        {
            if (!isVisited(visited, visitedCount, currEdge->dest))
            {
                Enqueue(&queue, currEdge->dest);

                strcpy(visited[visitedCount], currEdge->dest);
                visitedCount++;
            }

            currEdge = currEdge->nextEdge;
        }
    }
}
