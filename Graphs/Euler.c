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

// A graph has an euler path when
// 1. Every vertex has an even degree and one connected graph OR
// 2. There is only two vertices that have odd degree and one connected graph.

bool hasEulerPath(Graph g, int src, int dest) {
    if (src != dest) {
        if (GraphGetDegree(g, src) % 2 == 0 || GraphGetDegree(g, dest) % 2 == 0) {
            return false;
        }
    }
    for (int v = 0; v < GraphNumVertices(g); v++) {
        if (v != src && v != dest && GraphGetDegree(g, v) % 2 == 1) {
            return false;
        }
    }
    return true;
}

/* Pseudo Algorithm
hasEulerPath(G,src,dest):
|  Input  graph G, vertices src,dest
|  Output true if G has Euler path from src to dest
|         false otherwise
|
|  if src≠dest then
|     if degree(G,src) is even ∨ degree(G,dest) is even then
|        return false
|     end if
|  end if
|  for all vertices v ∈ G do
|     if v≠src ∧ v≠dest ∧ degree(G,v) is odd then
|        return false
|     end if
|  end for
|  return true
*/