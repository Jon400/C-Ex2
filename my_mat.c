#include "my_mat.h"
#include <stdlib.h>
#include <stdio.h>

int mat[MAT_SIZE][MAT_SIZE][MAT_SIZE + 1] = {0};

/*
This function initiate the dynamic programming table with the input matrix graph
*/
int getGraph ()
{
    size_t i, j;

    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            scanf("%d", &mat[i][j][0]);
        }
    }
    iterInitDistTab();
    return 0;
}

/*
This function will return the distance between two nodes through the minimum weighted path \
Using dynamic programming Floyd-warshall algorithm
*/
int getDist (int i, int j)
{
    int res = mat[i][j][MAT_SIZE];
    if (res == 0){
        return -1;
    }
    return res;
}

int iterInitDistTab()
{
    for (size_t k = 1; k <= MAT_SIZE; k++)
    {
        for (size_t i = 0; i < MAT_SIZE; i++)
        {
            for (size_t j = 0; j < MAT_SIZE; j++)
            {
                if (i != j)
                {
                    if ((mat[i][k - 1][k - 1] != 0) && (mat[k - 1][j][k - 1] != 0)) {
                        if (mat[i][j][k - 1] == 0)
                        {
                            mat[i][j][k] = (mat[i][k - 1][k - 1] + mat[k - 1][j][k - 1]);
                        }
                        else 
                        {
                            mat[i][j][k] = mat[i][j][k - 1] > (mat[i][k - 1][k - 1] + mat[k - 1][j][k - 1])
                                ? (mat[i][k - 1][k - 1] + mat[k - 1][j][k - 1]) : mat[i][j][k - 1];
                        }
                    }
                    else
                    {
                        mat[i][j][k] =  mat[i][j][k - 1];
                    }
                }

            }
            
        }  
    }
    return 0;
}

/*
This function returns if two nodes are connected
*/
int isConnected(int i, int j)
{
    int res = 0;
    res = getDist(i, j);
    if (res == -1)
    {
        return 0;
    }
    return 1;
}
/*
Will print the path between two nodes by backtracking on the dynamic programming table
*/
//int printPath(int i, int j, int k)
//{
//    if (k == 0)
//   {
//        returnb0
//    }
//}