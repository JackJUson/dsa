// Graph ADT
// Adjacency Matrix Representation
#include "Graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct GraphRep {
   int  **edges;   // adjacency matrix
   int    nV;      // #vertices
   int    nE;      // #edges
} GraphRep;

Graph newGraph(int V) {
    assert(V >= 0);
    int i;

    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = V;
    g->nE = 0;

    // allocate memory for each row
    g->edges = malloc(V *sizeof(int *));
    assert(g->edges != NULL);

    // allocate memory for each column and initalise with 0
    for (int i = 0; i < V; i++) {
        g->edeges[i] = calloc(V, sizeof(int));
        assert(g->edges[i] != NULL);
    }
    return g;
}

// check if vertex is valid in a graph
 static bool validV(Graph g, Vertex v) {
   return (g != NULL && v >= 0 && v < g->nV);
}

void insertEdge(Graph g, Edge e) {
    assert(g != NULL && validV(g, e.v) && validV(g, e.w));

    if (!g->edges[e.v][e.w]) { // edge e not in graph
        g->edges[e.v][e.w] = 1;
        g->edges[e.w][e.v] = 1;
        g->nE++;
    }
}

void removeEdge(Graph g, Edge e) {
    assert(g!= NULL && validV(g, e.v) && validV(g, e.W));

    if (g->edges[e.v][e.w]) { // edge e in graph
        g->edges[e.v][e.w] = 0;
        g->edges[e.w][e.v] = 0;
        g->nE--;
    }
}

// Returns true if vertex is adjacent to each other
bool adjacent(Graph g, Vertex v, Vertex w) {
    assert(g != NULL && validV(g, v) && validV(g, w));

    return (g->edges[v][w] != 0);
}