#include "my_mat.h"
#include <stdlib.h>

int mat[MAT_SIZE * MAT_SIZE * MAT_SIZE] = {0};

/*
This function initiate the dynamic programming table with the input matrix graph
*/
int getGraph (int graph [MAT_SIZE * MAT_SIZE])
{
    size_t i, j;

    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            mat[i, j, 0] = graph[i, j];
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
    if (k == 0)
    {
        return mat[i, j, k];
    }
    else if (mat[i, j, k] != 0)
    {
        return mat[i, j, k];
    }
    else
    {
        int d_i_j = getDist(i, j, k - 1);
        int d_i_j_k = getDist(i, k, k - 1) + getDist(k, j, k - 1);
        if (d_i_j == 0){
            mat[i, j, k] = d_i_j_k;
        }
        else if (d_i_j_k == 0)
        {
            mat[i, j, k] = d_i_j;
        }
        else
        {
            mat[i, j, k] = d_i_j > d_i_j_k ? d_i_j_k : d_i_j;
        }
        return mat[i, j, k];
    }
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