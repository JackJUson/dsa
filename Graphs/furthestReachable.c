
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

int *bfs(Graph g, int src);
int *getDistances(Graph g, int src);

// Returns the furthest vertex that is reachable from a given vertex
int furthestReachable(Graph g, int src) {
	// Find the end vertex of the longest path from src in graph

	// Distance of all vertices from src vertex
	int *dist = getDistances(g, src);
	int furthest = src;
	for (int i = 0; i < GraphNumVertices(g); i++) {
		// Get the highest distance value in the array and save its index (vertex)
		if (dist[i] != -1 && dist[i] >= dist[furthest]) {
			furthest = i;
		}
	}
	free(dist);
	return furthest;
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