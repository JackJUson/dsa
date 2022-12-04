
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

bool arrayContains(Vertex s, Vertex vs[], int index);

int dayTrip(Graph g, Vertex s, Vertex vs[]) {

    int index = 0;
    // Calculate the reachable vertices from Vertex s by fastEdges
    for (int j = 0; j < g->nV; j++) {
        if (g->fastEdges[s][j] && s != j) {
            vs[index] = j;
            index++;
            // Calculate the reachable vertices that are double fastEdges
            for (int k = 0; k < g->nV; k++) {
                if (g->fastEdges[j][k] && !arrayContains(k, vs, index) && s != k) {
                    vs[index] = k;
                    index++;
                }
            }
        }
    }

    // Calculate the reachable vertices from Vertex s by stdEdges
    for (int i = 0; i < g->nV; i++) {
        if (g->stdEdges[s][i] && !arrayContains(i, vs, index) && s != i) {
            vs[index] = i;
            index++;
        }
    }

    // Return size of the array
    return index;
}

bool arrayContains(Vertex s, Vertex vs[], int index) {
    for (int i = 0; i < index; i++) {
        if (vs[i] == s) {
            return true;
        }
    }
    return false;
}
