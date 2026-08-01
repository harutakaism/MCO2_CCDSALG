#include <stdio.h>
#include <string.h>

int main()
{
    int input = 0;

    do
    {
        printf("[1 - Add Vertex] Format: 1 <Name>\n");
        printf("[2 - Add Edge] Format: 2 <Name1> <Name2> <Weight>\n");
        printf("[3 - Get Degree] Format: 3 <Name>\n");
        printf("[4 - Edge Check] Format: 4 <Name1> <Name2>\n");
        printf("[5 - BFS] Format: 5 <Name>\n");
        printf("[6 - DFS] Format: 6 <Name>\n");
        printf("[7 - Path Check] Format: 7 <Name1> <Name2>\n");
        printf("[8 - MST] Format: 8\n");
        printf("[9 - Shortest Path] Format: 9 <Name1> <Name2>\n");
        printf("[10 - Print Graph] Format: 10\n");
        printf("[11 - End Program] Format: 11\n");
        printf("----------------------------------------------------\n");
        printf("Enter number here: ");
        do
        {
            scanf("%d", &input);
            if(input < 1 || input > 11)
            {
                printf("Error! Please enter values from 1-11!");
            }
        }
        while (input < 1 || input > 11);

        switch (input)
        {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 7: break;
            case 8: break;
            case 9: break;
            case 10: break;
            case 11: break;
        }
    }
    while(input != 11);
    return 0;
}
