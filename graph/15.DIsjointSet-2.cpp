// Disjoint Set Union by Rank and Path compression

// Cycle Detection in undirected graph and it cannot be applied to directed graph

// input
// -------
// 3
// 4
// 0 1
// 1 2
// 2 3

// output
// --------
// False

// input
// -------
// 4
// 4
// 0 1
// 1 2
// 2 3
// 3 1

// output
// --------
// True

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct node {
	int parent;
	int rank;
} node;

vector<node> dsuf;

// find Operator
int find(int v) { // Time Complexity - O(log(N))
	if (dsuf[v].parent == -1)
		return v;
	return dsuf[v].parent = find(dsuf[v].parent);
}

void union_op(int fromP, int toP) { // Time Complexity - O(log(N))
	// Union By Rank
	if (dsuf[fromP].rank > dsuf[toP].rank) // fromP has higher Rank
		dsuf[toP].parent = fromP;
	else if (dsuf[fromP].rank < dsuf[toP].rank) { // toP has higher Rank
		dsuf[fromP].parent = toP;
	}
	else {
		// Both have same rank and anyone can be made parent
		dsuf[fromP].parent = toP;
		dsuf[toP].rank += 1; // Incrementing rank of parent
	}
}


bool isCycle(vector<pair<int, int>>& edge_list) {
	for (auto p : edge_list) {
		int fromP = find(p.first); // find absolute parent of subset
		int toP = find(p.second);
		if (fromP == toP) {
			return true;
		}

		union_op(fromP, toP); // union of 2 sets
	}
	return false;
}

int main() {

	int E; // No of edges
	int V; // No of vertices
	cin >> E >> V;

	dsuf.resize(V); // mark all vertices as seperate subsets with only 1 element
	for (int i = 0; i < V; ++i) {
		dsuf[i].parent = -1;
		dsuf[i].rank = 0;
	}

	vector<pair<int, int>> edge_list; // Adjacency list
	for (int i = 0; i < E; ++i) {
		int from, to;
		cin >> from >> to;
		edge_list.push_back((from, to));

	}

	if (isCycle(edge_list)) {
		cout << "True" << "\n";
	}
	else {
		cout << "False" << "\n";
	}


	return 0;
}