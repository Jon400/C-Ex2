# define MAT_SIZE 10
/*
This function initiate the dynamic programming table with the input matrix graph
*/
int getGraph ();

/* Thia function will return the minimum weighted path between two nodes in the graph
Implemented by using the Floyd-Warshall algorithm with dynamic programming
*/
int getDist (int, int);

/*
This function returns if two nodes are connected using getDist function
*/
int isConnected(int, int);

/* 
This function build the dynamic three dimensional table which stored the values of the shortest path
*/
int iterInitDistTab();