#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

// check whether a given path is a Euler path
bool isEulerPath(Graph g, Edge e[], int nE) {
    assert(g != NULL);

    // Euler path has to include all edges of the graph
    if (g->nE != nE) {
        return false;
    }

    // Exact edges of Euler path must exist within graph
    for (int i = 0; i < nE; i++) {
        if (g->edges[e[i].v][e[i].w] == 0) {
            return false;
        }
    }

    // Edges must follow the path
    for (int i = 0; i < nE - 1; i++) {
        if (e[i].w != e[i + 1].v) {
            return false;
        }
    }

    // Euler path must hit all edges exactly once in the graph
    for (int i = 0; i < nE; i++) {
        for (int j = i + 1; j < nE; j++) {
            if (e[i].v == e[j].v && e[i].w == e[j].w) return false;
            if (e[i].v == e[j].w && e[i].w == e[j].v) return false;
        }
    }
    return true;
}