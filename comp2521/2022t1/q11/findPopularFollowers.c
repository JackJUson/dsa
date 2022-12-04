
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

// Worst case time complexity of this solution: O(...)
void findPopularFollowers(Graph g, int src, int followers[]) {
	// TODO

	int *diff = calloc(g->nV, sizeof(int));
	
	for (int i = 0; i < g->nV; i++) {
        for (AdjList curr = g->edges[i]; curr != NULL; curr = curr->next) {
            diff[i]++;          // Outdegree
            diff[curr->v]--;    // Indegree
        }
    }
}

