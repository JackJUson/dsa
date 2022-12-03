
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

void breadthFirstSearch(Graph g, int src) {
	// Calloc initialises the array with zeros
	int *visited = calloc(GraphNumVertices(g), sizeof(int));
	visited[src] = 1;

	Queue q = QueueNew();
	QueueEnqueue(q, src);

	while (!QueueIsEmpty(q)) {
		int v = QueueDequeue(q);
		printf("%d ", v);
		for (int w = 0; w < GraphNumVertices(g); w++) {
			if (GraphIsAdjacent(g, v, w) && !visited[w]) {
				visited[w] = 1;
				QueueEnqueue(q, w);
			}
		}
	}
	QueueFree(q);
	free(visited);
}


// visited[] // store previously visited node
//           // for each vertex 0..nV-1

// findPathBFS(G,src,dest):
// |  Input  graph G, vertices src,dest
// |
// |  for all vertices v∈G do
// |     visited[v]=-1
// |  end for
// |  found=false
// |  visited[src]=src
// |  enqueue src into queue Q
// |  while not found ∧ Q is not empty do
// |  |  dequeue v from Q
// |  |  if v=dest then
// |  |     found=true
// |  |  else
// |  |  |  for each (v,w) ∈ edges(G) with visited[w]=-1 do
// |  |  |     visited[w]=v
// |  |  |     enqueue w into Q
// |  |  |  end for
// |  |  end if
// |  end while
// |  if found then
// |     display path in dest..src order
// |  end if