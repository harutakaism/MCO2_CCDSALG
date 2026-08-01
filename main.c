#include <stdio.h>
#include <string.h>

int main()
{
    char input[258];
    char num[2];
    char cInput;
    int indexer, nChars, i;
    int boolspace = 0;

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

        //StringBuilder start
        indexer = 0;
        printf("Enter number and format here: ");
        scanf(" %c", &cInput);
        input[nChars++] = cInput;

        while(nChars < 257 && scanf("%c", &cInput) == 1 && cInput != '\n')
        {
            input[nChars++] = cInput;
        }

        input[nChars] = '\0';
        nChars = 0; //Reset nChars to make way for next one
        //StringBuilder ends
        strcpy(num,"");
        //To get the number
        for(i = 0; input[i] != ' ' && i < 2; i++)
        {
            num[i] = input[i];
        }

        if(strcmp(num,"1") == 0)
        {
            //Add Vertex
        }
        if(strcmp(num,"2") == 0)
        {
            //Add Edge
        }
        if(strcmp(num,"3") == 0)
        {
            //Get Degree
        }
        if(strcmp(num,"4") == 0)
        {
            //Edge-Check
        }
        if(strcmp(num,"5") == 0)
        {
            //BFS
        }
        if(strcmp(num,"6") == 0)
        {
            //DFS
        }
        if(strcmp(num,"7") == 0)
        {
            //Path-Check
        }
        if(strcmp(num,"8") == 0)
        {
            //MST
        }
        if(strcmp(num,"9") == 0)
        {
            //Shortest Path
        }
        if(strcmp(num,"10") == 0)
        {
            //Print Graph
        }
        if(strcmp(num,"11") == 0)
        {
            //Terminate Program
            printf("Program exited.");
        }
        else
        {
            printf("Error: Please enter the numbers from 1-11 and their respective format!\n");
        }
    }
    while(strcmp(input,"11") != 0);
    return 0;
}
