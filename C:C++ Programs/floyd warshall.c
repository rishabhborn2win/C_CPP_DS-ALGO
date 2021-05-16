// C Program for Floyd Warshall Algorithm
#include<stdio.h>

// Number of vertices in the graph
#define V 4
#define INF 99999

// A function to print the solution matrix
void printSolution(int dist[][V]);

// Solves the all-pairs shortest path 
// problem using Floyd Warshall algorithm
void floydWarshall (int graph[][V])
{
	int dist[V][V], i, j, k;

	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];


	for (k = 0; k < V; k++)
	{
		// Pick all vertices as source one by one
		for (i = 0; i < V; i++)
		{
			// Pick all vertices as destination for the
			// above picked source
			for (j = 0; j < V; j++)
			{
				// If vertex k is on the shortest path from
				// i to j, then update the value of dist[i][j]
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// Print the shortest distance matrix
	printSolution(dist);
}

/* A utility function to print solution */
void printSolution(int dist[][V])
{
	printf ("The following matrix shows the shortest distances"
			" between every pair of vertices \n");
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf ("%7d", dist[i][j]);
		}
		printf("\n");
	}
}

// driver program to test above function
int main()
{
		//Graph according to the given question
	int graph[V][V] = { {0, 3, INF, 7},
						{8, 0, 2, INF},
						{5, INF, 0, 1},
						{2, INF, INF, 0}
					};

	// Print the solution
	floydWarshall(graph);
	return 0;
}

