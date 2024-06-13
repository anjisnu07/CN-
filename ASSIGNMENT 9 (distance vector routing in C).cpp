#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#define NUM_NODES 5 
 
typedef struct { 
int costs[NUM_NODES]; 
} DistanceVector; 
void updateDistanceVector(DistanceVector dv[], int node, int newCost[]) { 
for (int i = 0; i < NUM_NODES; i++) { 
dv[node].costs[i] = newCost[i]; 
} 
} 
void printDistanceVector(DistanceVector dv[]) { 
printf("Distance Vector Table:\n"); 
for (int i = 0; i < NUM_NODES; i++) { 
printf("Node %d: ", i); 
for (int j = 0; j < NUM_NODES; j++) { 
printf("%d ", dv[i].costs[j]); 
} 
printf("\n"); 
} 
} 
void computeDistanceVector(DistanceVector dv[], int node, int linkState[][NUM_NODES]) { for 
(int i = 0; i < NUM_NODES; i++) { 
int minCost = INT_MAX; 
for (int j = 0; j < NUM_NODES; j++) { 
int cost = dv[node].costs[j] + linkState[j][i]; if 
(cost < minCost) { 
minCost = cost; 
} 
} 
dv[node].costs[i] = minCost; 
} 
} 
int main() { 
DistanceVector dv[NUM_NODES]; 
 
for (int i = 0; i < NUM_NODES; i++) { 
for (int j = 0; j < NUM_NODES; j++) { 
dv[i].costs[j] = (i == j) ? 0 : INT_MAX; 
} 
} 
int linkState[NUM_NODES][NUM_NODES] = { 
{0, 1, 3, INT_MAX, INT_MAX}, 
{1, 0, 1, 4, INT_MAX}, 
{3, 1, 0, 2, 7}, 
{INT_MAX, 4, 2, 0, 5}, 
{INT_MAX, INT_MAX, 7, 5, 0} 
}; 
for (int i = 0; i < NUM_NODES; i++) { 
for (int j = 0; j < NUM_NODES; j++) { 
dv[i].costs[j] = linkState[i][j]; 
} 
} 
for (int i = 0; i < NUM_NODES; i++) { 
computeDistanceVector(dv, i, linkState); 
} 
printDistanceVector(dv); 
return 0; 
} 