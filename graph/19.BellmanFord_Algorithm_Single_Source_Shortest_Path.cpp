// BellmanFOrd Algorithm -> Single Source Shortest Path

// Dijkstra vs Bellmanford

// 1. Dijkstra and Bellmanford algorithms does not find the negative edge weight cycles.
// 2. Dijkstra cannot find negative edge weight cycle but Bellmanford can.
// 3. Bellmanford algorithm is well suited for distributed system.

// Approach - like Dp, the algorithm calculates shortest path in a bottom up manner.

// Bellmanford(Bf) will definetly work if all edges are positive in undirected graph.
// Note: Bf doest not find shortest path for undirected graph if it has any - ve edge weight
// Because - ve edge weight in undirected graph means - ve edge weight cycle.

// Time COmplexity - O(VE)

// Bellmanford Algorithm
// 1. Initialize all distance values as infinity except source node
// 2. Repeat V - 1 times
// 2.1 If d[U] + cost(Uv) < d[v]
// then update d[v]
// else
// 	skip
// 	3. Relax all vertices once more. If we find any shortest distance value then we have - ve edge weight cycle else we dont


// -VE Edge Cycle Condition
// --------------------------

// If vertices  = V
// then we relax (V-1) times
// If we see any step where none of the vertex gets new shortest path, then definitely we won't have any negative edge cycle
// else
// we can relax once more and see if we can have any shortest path

// BellmanFOrd Algorithm -> Single Source Shortest Path

// Dijkstra vs Bellmanford

// 1. Dijkstra and Bellmanford algorithms does not find the negative edge weight cycles.
// 2. Dijkstra cannot find negative edge weight cycle but Bellmanford can.

// Bellmanford(Bf) will definetly work if all edges are positive in undirected graph.
// Note: Bf doest not find shortest path for undirected graph if it has any - ve edge weight
// Because - ve edge weight in undirected graph means - ve edge weight cycle.

// Time COmplexity - O(VE)

// Bellmanford Algorithm
// 1. Initialize all distance values as infinity except source node
// 2. Repeat V - 1 times
// 2.1 If d[U] + cost(Uv) < d[v]
// then update d[v]
// else
// 	skip
// 	3. Relax all vertices once more. If we find any shortest distance value then we have - ve edge weight cycle else we dont


// -VE Edge Cycle Condition
// --------------------------

// If vertices  = V
// then we relax (V-1) times
// If we see any step where none of the vertex gets new shortest path, then definitely we won't have any negative edge cycle
// else
// we can relax once more and see if we can have any shortest path

//Input
// 5 8
// 0 1 - 1
// 0 2 4
// 1 2 3
// 1 3 2
// 1 4 2
// 3 2 5
// 3 1 1
// 4 3 - 3

// Output
// U -> V: 0 -> 1 Cost to reach 0 from source 0 = -1
// U -> V: 1 -> 2 Cost to reach 1 from source 0 = 2
// U -> V: 4 -> 3 Cost to reach 4 from source 0 = -2
// U -> V: 1 -> 4 Cost to reach 1 from source 0 = 1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct edge {
	int src;
	int dst;
	int wt;
} edge;

int V, E;

void bellmanford(vector<edge>& Edges) {
	int parent[V]; // Stores Shortest Path Structure
	int cost_parent[V]; // Cost of the node to parent edge weight
	vector<int> value(V, INT_MAX); // keep shortest path values to each vertex from source

	// Assuming start point as Node - 0
	parent[0] = -1; // Start node has no parent
	value[0] = 0; // Start node has value = 0 to get picked first

	// Include (V-1) edges to cover all V vertices
	bool updated;

	for (int i = 0; i < V - 1; ++i) {
		updated = false;
		for (int j = 0; j < E; ++j) {
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if (value[U] != INT_MAX and value[U] + wt < value[V]) {
				value[V] = value[U] + wt;
				parent[V] = U;
				cost_parent[V] = value[V];
				updated = true;
			}
		}

		if (updated == false) {
			break;
		}
	}

	// Now check by relaxing once more if we have negative edge cycle
	for (int j = 0; j < E and updated == true; ++j) {
		int U = Edges[j].src;
		int V = Edges[j].dst;
		int wt = Edges[j].wt;
		if (value[U] != INT_MAX and value[U] + wt < value[U]) {
			cout << "Graph has negative edge weight cycle \n";
			return;
		}
	}

	// Print Shortest Path Cycle
	for (int i = 1; i < V; ++i) {
		cout << "U -> V: " << parent[i] << " -> " << i << " Cost to reach " << parent[i] << " from source 0 = " << value[i] << "\n";
	}

}


int main() {
	cin >> V >> E; // Enter no of Vertices and Edges

	vector<edge> Edges(E);

	// Now input all E edges
	int src, dst, wt;
	for (int i = 0; i < E; ++i) {
		cin >> src >> dst >> wt;
		Edges[i].src = src;
		Edges[i].dst = dst;
		Edges[i].wt = wt;
	}

	bellmanford(Edges);
	return 0;
}
