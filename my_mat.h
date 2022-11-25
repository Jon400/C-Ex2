# define MAT_SIZE 10
/*
This function initiate the dynamic programming table with the input matrix graph
*/
int getGraph (int graph [MAT_SIZE * MAT_SIZE]);

/* Thia function will return the minimum weighted path between two nodes in the graph
Implemented by using the Floyd-Warshall algorithm with dynamic programming
*/
int getDist (int, int, int, int *);

/* 
This function will do backtracking on the table in order to print the exactly path between two nodes

int printPath (int, int, int, int *); */