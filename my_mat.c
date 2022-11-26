#include "my_mat.h"
#include <stdlib.h>
#include <stdio.h>

int mat[MAT_SIZE][MAT_SIZE][MAT_SIZE] = {0};

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
    return 0;
}

/*
This function will return the distance between two nodes through the minimum weighted path \
Using dynamic programming Floyd-warshall algorithm
*/
int getDist(int i, int j, int k)
{
    if (i == j)
    {
        mat[i][j][k] = 0;
        return mat[i][j][k];
    }
    else if (k == 0)
    {
        return mat[i][j][k];
    }
    else if (mat[i][j][k] != 0)
    {
        return mat[i][j][k];
    }
    else
    {
        int d_i_j = 0; 
        int d_i_k = 0;
        int d_k_j = 0;
        d_i_j = getDist(i, j, k - 1);
        d_i_k = getDist(i, k, k - 1);
        d_k_j = getDist(k, j, k - 1);
        if (d_i_j == 0){
            if (((d_i_k != 0) || (i == k)) && ((d_k_j != 0) || (j == k)))
            {
                mat[i][j][k] = d_i_k + d_k_j;
            }
            else
            {
                mat[i][j][k] = 0;
            }
        }
        else if (((d_i_k == 0) && (i != k)) || ((d_k_j == 0) && (j != k)))
        {
            mat[i][j][k] = d_i_j;
        }
        else
        {
            mat[i][j][k] = d_i_j > (d_i_k + d_k_j) ? (d_i_k + d_k_j) : d_i_j;
        }
        return mat[i][j][k];
    }
}

int iterGetDist()
{
    for (size_t k = 1; k < MAT_SIZE; k++)
    {
        for (size_t i = 0; i < MAT_SIZE; i++)
        {
            for (size_t j = 0; j < MAT_SIZE; j++)
            {
                if (mat[i][j][k - 1] == 0)
                {
                    if (((mat[i][k][k-1] != 0) || (i == k)) && ((mat[k][j][k-1] != 0) || (j == k)))
                    {
                        mat[i][j][k] = mat[i][k][k-1] + mat[k][j][k-1];
                    }
                    else
                    {
                        mat[i][j][k] = 0;
                    }
                }
                else if (((mat[i][k][k-1] == 0) && (i != k)) || ((mat[k][j][k-1] == 0) && (j != k)))
                {
                    mat[i][j][k] = mat[i][j][k - 1];
                }
                else
                {
                     mat[i][j][k] = mat[i][j][k-1] > (mat[i][k][k-1] + mat[k][j][k-1]) ?
                      (mat[i][k][k-1] + mat[k][j][k-1]) : mat[i][j][k-1];
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
    res = getDist(i, j, MAT_SIZE - 1);
    if (res == 0)
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