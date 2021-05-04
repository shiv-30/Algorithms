// Prims Algorithm

// TO find minimum Minimum SPanning Tree

// Time Complexity - O(V^2)

// Approach - greedy

#include <iostream>
#include <bits/stdc++.h>
#define V 6 // No of Vertices

using namespace std;

int selectMinVertex(vector<int>& value, vector<bool>& setMST) {
	int minimum = INT_MAX;
	int vertex;
	for (int i = 0; i < V; ++i) {
		if (setMST[i] == false && value[i] < minimum) {
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}

void findMST(int graph[V][V]) {
	int parent[V]; // Stores MST
	vector<int> value(V, INT_MAX); // Used for edge Relaxation
	vector<bool> setMST(V, false); // True -> Vertex is included in MST

	// Assuming start point as Node - 0
	parent[0] = -1; // Starting Node has no parent
	value[0] = 0; // start node has value - 0 to get picked 1st

	// From MST with (V-1) edges
	for (int i = 0; i < V - 1; ++i) {
		// Select best Vertex by applying greedy method
		int U = selectMinVertex(value, setMST);
		setMST[U] = true; // Include new vertex in MST

		// Relax adjacent vertices (not yet included in MST)
		for (int j = 0; j < V; ++j) {

			/*
				3 Constraints to relax -:
					1.Edge is present from U to j.
					2.Vertex j is not included in MST.
					3.Edge weight is smaller than current edge weight
			*/

			if (graph[U][j] !=  0 && setMST[j] == false && graph[U][j] < value[j]) {
				value[j] = graph[U][j];
				parent[j] = U;
			}
		}
	}

	// Print MST
	for (int i = 1; i < V; ++i) {
		cout << " " << parent[i] << " -> " << i << "wt -> " << graph[parent[i]][i] << "\n";
	}

}

int main() {
	int graph[V][V] = {
		{0, 4, 6, 0, 0, 0},
		{4, 0, 6, 3, 4, 0},
		{6, 6, 0, 1, 8, 0},
		{0, 3, 1, 0, 2, 3},
		{0, 4, 8, 2, 0, 7},
		{0, 0, 0, 3, 7, 0}

	};
	findMST(graph);
	return 0;
}