// Kruskal's Algorithm For Finding MST

// Using Disjoint Cell

// Greedy Algorithm

// Edge List

// Steps

// 1) Sort all the edges in non-decreasing order of their weight.
// 2)
// 	2.1) Pick the smallest edge
// 	2.2) check if the new edge forms a cycle in out spanning tree being formed (DSUF)
// 	2.3) If the cycle is not formal - > include the edge
// 		 Otherwise  -> Discard the edge

// 3) Repeat step -2 unless (V-1) edges are included in MST.

// Time Complexity - T(ElogE + ElogV)
// ElogE - Sorting E edges
// ElogV - DSUF on V vertices (applied for max of E No of times)
// ElogV - Find and union Operation on E edges having V vertices

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct node {
	int parent;
	int rank;
} node;

typedef struct Edge {
	int src;
	int dst;
	int wt;
} Edge;

vector<node> dsuf;
vector<Edge> mst;

// Find Operation

int find(int v) {
	if (dsuf[v].parent == -1) {
		return v;
	}
	return dsuf[v].parent = find(dsuf[v].parent); // Path compression
}

void union_op(int fromP, int toP) {
	// Union
	if (dsuf[fromP].rank > dsuf[toP].rank) { // fromP has higher rank
		dsuf[toP].parent = fromP;
	}
	else if (dsuf[fromP].rank < dsuf[toP].rank) { // toP has higher rank
		dsuf[fromP].parent = toP;
	}
	else {
		// Both have same rank and so anyone can made as parent
		dsuf[fromP].parent = toP;
		dsuf[toP].rank += 1; // Increase rank of parent
	}
}

bool comparator(Edge a, Edge b) {
	return a.wt < b.wt;
}

void printEdgeList(vector<Edge>& edge_list) {
	for (auto p : edge_list) {
		cout << "src :" << p.src << " dst: " << p.dst << " wt: " << p.wt << "\n";
		cout << " ====================================================\n";
	}
}

void Kruskals(vector<Edge>& edge_list, int V, int E) {
	// cout << "Edge list before sort \n";
	// printEdgeList(edge_list);
	sort(edge_list.begin(), edge_list.end(), comparator);
	// cout << "edge_list after sort \n";
	// printEdgeList(edge_list);

	int i = 0;
	int j = 0;
	while (i < V - 1 && j < E) {
		int fromP = find(edge_list[j].src); // find absolute parent of subset
		int toP = find(edge_list[j].dst);

		if (fromP == toP) {
			++j;
			continue;
		}

		// Union Operation
		union_op(fromP, toP); // Union of 2 subsets
		mst.push_back(edge_list[j]);
		++i;
	}
}

// Display the format MST
void printMST(vector<Edge>& mst) {
	cout << "MST formed is \n";
	for (auto p : mst) {
		cout << "src : " << p.src << " dst: " << p.dst << " wt: " << p.wt << "\n";
	}
}

int main() {
	int E; // No of edges
	int V; // No of Vertices (0 to V-1)
	cin >> E >> V;

	dsuf.resize(V); // Mark all vertices as separate subsets with only 1 element
	for (int i = 0; i < V; ++i) { // Mark all nodes as independent set
		dsuf[i].parent = -1;
		dsuf[i].rank = 0;
	}
	vector<Edge> edge_list; // Adjacency list
	Edge temp;
	for (int i = 0; i < E; ++i) {
		int from, to, wt;
		cin >> from >> to >> wt;
		temp.src = from;
		temp.dst = to;
		temp.wt = wt;
		edge_list.push_back(temp);
	}
	Kruskals(edge_list, V, E);
	printMST(mst);

	return 0;
}