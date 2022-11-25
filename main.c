#include "my_mat.h"
#include <stdio.h>
#include <stdlib.h>

int graph [MAT_SIZE][MAT_SIZE] = {0};
int main() {
    size_t i, j = 0;

    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            scanf("%d", &graph[j][i]);
        }  
    } 

    getGraph (graph);

    //int bb = getDist(9, 1, MAT_SIZE - 1);

    printf("%d\n", getDist(9, 3, MAT_SIZE - 1));
}
