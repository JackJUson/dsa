
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

void dfs(Graph g, int *path, int nV, int src);

// Returns the number of vertices that are reachable from given vertex
int numReachable(Graph g, int src) {
	int nV = GraphNumVertices(g);
	int *path = calloc(nV, sizeof(int));
	dfs(g, path, nV, src);
	int pathLength = 0;
	for (int i = 0; i < nV; i++) {
		if (path[i]) pathLength++;
	}
	return pathLength;
}

void dfs(Graph g, int *path, int nV, int src) {
	path[src] = 1;
	for (int w = 0; w < nV; w++) {
		if (GraphIsAdjacent(g, src, w) && !path[w]) {
			dfs(g, path, nV, w);
		}
	}
}