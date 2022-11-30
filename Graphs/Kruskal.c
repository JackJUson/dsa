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