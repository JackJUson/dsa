#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "PQ.h"

/*
PrimMST(G):
|  Input  graph G with n nodes
|  Output a minimum spanning tree of G
|
|  MST=empty graph
|  usedV={0}
|  unusedE=edges(g)
|  while |usedV| < n do
|  |  find e=(s,t,w) ∈ unusedE such that {
|  |     s ∈ usedV ∧ t ∉ usedV 
|  |       ∧ w is min weight of all such edges
|  |  }
|  |  MST = MST ∪ {e}
|  |  usedV = usedV ∪ {t}
|  |  unusedE = unusedE \ {e}
|  end while
|  return MST
*/
