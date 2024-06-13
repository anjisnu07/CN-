#include <stdio.h> 
#include <stdlib.h> 
#define NUM_NODES 5 
typedef struct { 
int cost[NUM_NODES]; 
} LinkState; 
void updateLinkState(LinkState ls[], int node, int newCost[]) { for 
(int i = 0; i < NUM_NODES; i++) { 
ls[node].cost[i] = newCost[i]; 
ls[i].cost[node] = newCost[i]; 
} 
} 
 
void printLinkState(LinkState ls[]) { 
printf("Link State Table:\n"); 
for (int i = 0; i < NUM_NODES; i++) { 
printf("Node %d: ", i); 
for (int j = 0; j < NUM_NODES; j++) { 
printf("%d ", ls[i].cost[j]); 
} 
 
printf("\n"); 
} 
} 
 
int main() { 
LinkState ls[NUM_NODES]; 
for (int i = 0; i < NUM_NODES; i++) { 
for (int j = 0; j < NUM_NODES; j++) { 
ls[i].cost[j] = (i == j) ? 0 : rand() % 10 + 1; 
 
 
 
 
 
} 
} 
printLinkState(ls); 
int newCost[NUM_NODES] = {0, 5, 2, 999, 8}; 
updateLinkState(ls, 0, newCost); 
printLinkState(ls); 
 
return 0; 
}