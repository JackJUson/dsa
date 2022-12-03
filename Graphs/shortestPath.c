
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

// Returns the number of edges on the shortest path between two vertices
int shortestDistance(Graph g, int src, int dest) {
	int *visited = malloc(GraphNumVertices(g)* sizeof(int));
	for (int i = 0; i < GraphNumVertices(g); i++) {
		visited[i] = -1;
	}
	bool found = false;
	visited[src] = src;

	Queue q = QueueNew();
	QueueEnqueue(q, src);
	while (!found && !QueueIsEmpty(q)) {
		int v = QueueDequeue(q);
		if (v == dest) {
			found = true;
		} else {
			for (int w = 0; w < GraphNumVertices(g); w++) {
				if (GraphIsAdjacent(g, v, w) && visited[w] == -1) {
					visited[w] = v;
					if (w == dest) {
						found = true;
					}
					QueueEnqueue(q, w);
				}	
			}
		}
	}
	QueueFree(q);

	// Calculate the distance using predecessor array
	int sum = 0;
	while (dest != src) {
		sum++;
		dest = visited[dest];
	}

	free(visited);
	
	if (found) {
		return sum;
	}
	return -1;
}
