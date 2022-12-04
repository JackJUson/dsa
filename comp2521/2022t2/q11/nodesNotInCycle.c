
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

static int doHasCycle(Graph g, Vertex v, Vertex prev, int *visited);
int GraphHasCycle(Graph g, int notInCycle[]);

// Worst case time complexity of this solution: O(...)
void nodesNotInCycle(Graph g, int notInCycle[]) {
    GraphHasCycle(g, notInCycle);
}

int GraphHasCycle(Graph g, int notInCycle[]) {
    int *visited = calloc(GraphNumVertices(g), sizeof(int));
    assert(visited != NULL); // lazy error checking
    
    for (int v = 0; v < GraphNumVertices(g); v++) {
        for (int i = 0; i < GraphNumVertices(g); i++) {
            visited[i] = -1;
        }
        if (doHasCycle(g, v, v, visited)) {
            notInCycle[v] = 0;
        } else {
            notInCycle[v] = 1;
        }
    }

    free(visited);
    return 0;
}

static int doHasCycle(Graph g, Vertex src, Vertex v, int *visited) {
    visited[v] = 1;
    for (int w = 0; w < GraphNumVertices(g); w++) {
        if (GraphIsAdjacent(g, v, w)) {
            if (w == src) {
                return 1;
            }
            if (visited[w] == -1) {
                if (doHasCycle(g, src, w, visited)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}