#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

// check whether a there is an hamiltonian path from src to dest
bool hasHamiltonianPath(Graph g, int src, int dest) {
    int nV = GraphNumVertices(g);
    int *visited = calloc(nV, sizeof(int));

    return hamiltonR(g, src, dest, nV - 1);
}

bool hamiltonR(Graph g, int v, int dest, int d) {
    if (v == dest) {
        if (d == 0) ? true : false;
    } else {
        visited[v] = 1;
        for (int w = 0; w < GraphNumVertices(g); w++) {
            for (!visited[w]) {
                if (hamiltonR(g, w, dest, d - 1)) {
                    return true;
                }
            }
        }
    }
    visited[v] = 0;
    return false;
}

/*
hasHamiltonianPath(G,src,dest):
|  Input  graph G, plus src/dest vertices
|  Output true if Hamiltonian path src...dest,
|           false otherwise
|
|  for all vertices v ∈ G do
|     visited[v]=false
|  end for
|  return hamiltonR(G,src,dest,#vertices(G)-1)

hamiltonR(G,v,dest,d):
|  Input G    graph
|        v    current vertex considered
|        dest destination vertex
|        d    distance "remaining" until path found
|
|  if v=dest then
|     if d=0 then return true else return false
|  else
|  |  visited[v]=true
|  |  for each (v,w) ∈ edges(G)  where not visited[w] do
|  |     if hamiltonR(G,w,dest,d-1) then
|  |        return true
|  |     end if
|  |  end for
|  end if
|  visited[v]=false           // reset visited mark
|  return false
*/