#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "PQ.h"

// Search for MST by Kruskal's Algorithm
Graph KruskalMST(Graph g) {
    int nV = GraphNumVertices(g);

    // Empty Graph with just the vertices
    Graph mst = GraphNew();
    int *sortedEdges = GraphSortEdgesByWeight(g);
    int sortedEdgeLength = GraphNumEdges(g);
    for (int i = 0; i < sortedEdgeLength; i++) {
        GraphInsertEdge(mst, sortedEdges[i]);
        if (GraphHasCycle(mst)) {
            GraphRemoveEdge(mst, sortedEdges[i]);
        }
        if (GraphNumEdges(mst) == nV - 1) {
            return mst;
        }
    }
    return mst;
}

/* Pseudo Algorithm
KruskalMST(G):
|  Input  graph G with n nodes
|  Output a minimum spanning tree of G
|
|  MST=empty graph
|  sort edges(G) by weight
|  for each e ∈ sortedEdgeList do
|  |  MST = MST ∪ {e}  // add edge
|  |  if MST has a cyle then
|  |     MST = MST \ {e}  // drop edge 
|  |  end if
|  |  if MST has n-1 edges then
|  |     return MST
|  |  end if
|  end for
*/

Graph GraphMST(Graph g) {
    int nV = GraphNumVertices(g);

    // Create a new empty graph
    Graph mst = GraphNew(nV);
    PQ pq = PQNew();
    
    // Loop through the adjacency matrix containing weights of edges
    for (int v = 0; v < nV; v++) {
        for (int w = 0; w < nV; w++) {
            // If vertices are different and an edge is adjacent
            if (w != v && g->edges[v][w] != 0) {
                double weight = g->edges[v][w];
                PQInsert(pq, (Edge){v, w, weight});
            }
        }
    }

    // If the queue is not empty, add lowest weight edge into MST
    while (mst->nE < g->nV - 1 && !PQIsEmpty(pq)) {
        Edge e = PQExtract(pq);
        GraphInsertEdge(mst, e);
        // If graph has a cycle, remove the added edge
        if (GraphHasCycle(mst)) {
            GraphRemoveEdge(mst, e.v, e.w);
        }
    }
    
    PQFree(pq);
    if (mst->nE == g->nV -1) {
        return mst;
    } else {
        GraphFree(mst);
        return NULL;
    }
}