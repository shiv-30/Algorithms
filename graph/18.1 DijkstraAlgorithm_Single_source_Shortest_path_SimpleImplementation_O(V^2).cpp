// Dijkstra's Algorithm -> Single Source shortest path

// Given a graph find the shortest path from source to all other vertices.

// Note: MST and SPG(Shortest Path Graph) may or may not be same.

// Algorithm

// 1 Maintain a set of processed nodes
// 2 Assign all node with distance value = infinity except the source node (0)
// 3 Repeat the following (unless all the vertices are included)
// 	3.1 Pick min value vertex which is not already processed.
// 	3.2 Include this selected node in processed Set
// 	3.3 Update all the adjacent node distances.
// 	If the (new distance < old distance) then update
// 	else
// 		skip

// Prerequisites
// 1 Use a visited array / set
// 2 Use value array/ map
// 3 Store shortest path graph use parent array u -> v parent[v] = u

// Time Complexity
// 1 O(V^2) - simple implementation (adjacency matrix)
// 2 O(ElogV) - adjlist + min heap


// Dijkstra's Algorithm -> Single Source shortest path

// Given a graph find the shortest path from source to all other vertices.

// Note: MST and SPG(Shortest Path Graph) may or may not be same.

// Algorithm

// 1 Maintain a set of processed nodes
// 2 Assign all node with distance value = infinity except the source node (0)
// 3 Repeat the following (unless all the vertices are included)
// 	3.1 Pick min value vertex which is not already processed.
// 	3.2 Include this selected node in processed Set
// 	3.3 Update all the adjacent node distances.
// 	If the (new distance < old distance) then update
// 	else
// 		skip

// Prerequisites
// 1 Use a visited array / set
// 2 Use value array/ map
// 3 Store shortest path graph use parent array u -> v parent[v] = u

// Time Complexity
// 1 O(V^2) - simple implementation (adjacency matrix)
// 2 O(ElogV) - adjlist + min heap

// Simple Implementation
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define V 6 // No of vertices 

int selectMinVertex(vector<int>& value, vector<bool>& processed) {
	int minimum = INT_MAX;
	int vertex;
	for (int i = 0; i < V; ++i) {
		if (processed[i] == false && value[i] < minimum) {
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}

void dijkstra(int graph[V][V]) {
	int parent[V]; // Stores Shortest Path Structure
	vector<int> value(V, INT_MAX); // keeps shortest path values to each vertexfrom  source
	vector<bool> processed(V, false); // true - vertex is processed

	// Assuming start point Node - 0
	parent[0] = -1; // start node has no parent
	value[0] = 0; // start node has value 0 to get it picked

	// Include (V-1) edges to cover all vertices
	for (int i = 0; i < V - 1; ++i) {
		int U = selectMinVertex(value, processed);
		processed[U] = true; // Include new vertex in shortest Path graph

		// Relax adjacent vertices (not yet included in shortest path)
		for (int j = 0; j < V; ++j) {
			// 3 Conditions to relax:-
			// 	1. Edge is present from U to j.
			// 	2. Vertex j is not included in hsortest ath graph
			// 	3. Edge weight is smaller than current edge weight

			if (graph[U][j] != 0 && processed[j] == false && value[U] != INT_MAX && (value[U] + graph[U][j] < value[j])) {

				value[j] = value[U] + graph[U][j];
				parent[j] = U;
			}
		}

	}

	// Print Shortest Pair Graph
	for (int i = 1; i < V; ++i) {
		cout << "U -> V: " << parent[i] << " -> " << i << " wt = " << graph[parent[i]][i] << "\n";
	}
}

int main() {
	int graph[V][V] = {
		{1, 0, 4, 2, 7, 0},
		{4, 4, 0, 3, 5, 0},
		{0, 2, 3, 0, 4, 0},
		{0, 7, 5, 4, 0, 7},
		{0, 0, 0, 6, 7, 0}
	};
	dijkstra(graph);
	return 0;
}