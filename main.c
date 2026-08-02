#include <stdio.h>
#include "Graph.h"
#include "GraphTraversals.h"
#include "MST.h"

int main()
{
    GraphTag *graph = createGraph();
    int command;
    char name1[257];
    char name2[257];
    int weight;

    if(graph == NULL)
    {
        return 1;
    }

    while(1)
    {
        if(scanf("%d", &command) != 1)
        {
            break;
        }

        if(command == 1)
        {
            if(scanf("%256s", name1) == 1)
            {
                addVertex(graph, name1);
            }
        }
        else if(command == 2)
        {
            if(scanf("%256s %256s %d", name1, name2, &weight) == 3)
            {
                if(weight >= 1 && weight <= 100)
                {
                    addEdge(graph, name1, name2, weight);
                }
            }
        }
        else if(command == 3)
        {
            if(scanf("%256s", name1) == 1)
            {
                printf("%d\n", getDegree(graph, name1));
            }
        }
        else if(command == 4)
        {
            if(scanf("%256s %256s", name1, name2) == 2)
            {
                printf("%d\n", edgeCheck(graph, name1, name2));
            }
        }
        else if(command == 5)
        {
            if(scanf("%256s", name1) == 1)
            {
                breadthFirstSearch(graph, name1);
            }
        }
        else if(command == 6)
        {
            if(scanf("%256s", name1) == 1)
            {
                depthFirstSearch(graph, name1);
            }
        }
        else if(command == 7)
        {
            if(scanf("%256s %256s", name1, name2) == 2)
            {
                printf("%d\n", pathCheck(graph, name1, name2));
            }
        }
        else if(command == 8)
        {
            GraphTag *mst = minimumSpanningTree(graph);

            if(mst != NULL)
            {
                printGraph(mst, "MST");
                destroyGraph(mst);
            }
        }
        // else if(command == 9)
        // {
        //     if(scanf("%256s %256s", name1, name2) == 2)
        //     {
        //         shortestPath(graph, name1, name2);
        //     }
        // }
        else if(command == 10)
        {
            printGraph(graph, "G");
        }
        else if(command == 11)
        {
            break;
        }
    }

    destroyGraph(graph);
    return 0;
}
