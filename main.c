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
        else if (input == 'C')
        {
            scanf("%d", &node_a);
            scanf("%d", &node_b);
            res = getDist(node_a, node_b);
            printf("%d\n", res);
        }
        else if (input == 'D'){
            return 0;
        }
        else
        {
            continue;
        }
    }

    return 0;
}
