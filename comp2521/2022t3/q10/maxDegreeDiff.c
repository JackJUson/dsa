
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

// int maxDegreeDiff(Graph g) {
//     // calculate indegree
//     int n = GraphNumVertices(g);

//     int indegree = 0;
//     int indegrees[n];
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             for (AdjList n1 = g->edges[j]; n1 != NULL; n1 = n1->next) {
//                 if (n1->v == i) {
//                     indegree++;
//                 }
//             }
//         }
//         indegrees[i] = indegree;
//         indegree = 0;
//     }

//     // calculate outdegree
//     int outdegree = 0;
//     int outdegrees[n];
//     for (int i = 0; i < n; i++) {
//         for (AdjList n2 = g->edges[i]; n2 != NULL; n2 = n2->next) {
//             outdegree++;
//         }
//         outdegrees[i] = outdegree;
//         outdegree = 0;
//     }

//     // save indegree and outdegree in array 
//     // (index of array would represent the vertex number)
//     int max = 0;

//     // calculate max abs degree diff
//     for (int k = 0; k < n; k++) {
//         int degreediff = abs(indegrees[k] - outdegrees[k]);
//         if (max < degreediff) {
//             max = degreediff;
//         }
//     }
//     return max;
// }

int maxDegreeDiff(Graph g) {
    // TODO
    int *diff = calloc(g->nV, sizeof(int));

    for (int i = 0; i < g->nV; i++) {
        for (AdjList curr = g->edges[i]; curr != NULL; curr = curr->next) {
            diff[i]--;          // Outdegree
            diff[curr->v]++;    // Indegree
        }
    }

    int maxDiff = 0;
    for (int i = 0; i < g->nV; i++) {
        if (abs(diff[i]) > maxDiff) {
            maxDiff = abs(diff[i]);
        }
    }
    
    free(diff);
    return maxDiff;
}