#include "my_mat.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int node_a, node_b = 0;
    char input = 0;
    int res = 0;

    while (scanf("%c", &input) != EOF){
        if (input == 'A'){
            getGraph ();
            iterGetDist();
        }
        else if (input == 'B')
        {
            scanf("%d", &node_a);
            scanf("%d", &node_b);
            res = isConnected(node_a, node_b);
            if (res)
            {
                printf("True\n");
            }
            else
            {
                printf("False\n");
            }
        }
        else
        {
            continue;
        }
    }

    //int bb = getDist(9, 1, MAT_SIZE - 1);

}
