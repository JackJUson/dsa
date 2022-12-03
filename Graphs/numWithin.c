
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

int *bfs(Graph g, int src);
int *getDistances(Graph g, int src);

// Determines the number of vertices that are within a path
int numWithin(Graph g, int src, int dist) {
	// Get the maximum number of vertices from a given dist from src vertex
	
	int nV = GraphNumVertices(g);
	int *distances = getDistances(g, src);

	int count = 0;
	for (int i = 0; i < nV; i++) {
		if (distances[i] >= 0 && distances[i] <= dist) {
			count++;
		}
	}
	return count;
}

int *getDistances(Graph g, int src) {
	int nV = GraphNumVertices(g);
	int *pred = bfs(g, src);

	int *distances = malloc(nV * sizeof(int));
	for (int i = 0; i < nV; i++) {
		if (pred[i] == -1) {
			distances[i] = -1;
		} else {
			int distance = 0;
			int curr = i;
			while (curr != src) {
				distance++;
				curr = pred[curr];
			}
			distances[i] = distance;
		}
	}

	free(pred);
	return distances;
}

int *bfs(Graph g, int src) {
	int nV = GraphNumVertices(g);
	int *pred = malloc(nV * sizeof(int));
	for (int i = 0; i < nV; i++) {
		pred[i] = -1;
	}
	
	Queue q = QueueNew();
	QueueEnqueue(q, src);
	pred[src] = src;

	while (!QueueIsEmpty(q)) {
		int v = QueueDequeue(q);
		for (int w = 0; w < nV; w++) {
			if (GraphIsAdjacent(g, v, w) && pred[w] == -1) {
				pred[w] = v;
				QueueEnqueue(q, w);
			}
		}
	}

	QueueFree(q);
	return pred;
}