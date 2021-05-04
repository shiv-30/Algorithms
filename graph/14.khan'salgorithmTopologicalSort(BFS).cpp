// Topological Sort

// Khan's Algorithm (BFS)

// Time Complexity - O(v+E)
// Space Complexity - O(V)


// A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0.
// Proof: There’s a simple proof to the above fact is that a DAG does not contain a cycle which means that all paths will be of finite length. Now let S be the longest path from u(source) to v(destination). Since S is the longest path there can be no incoming edge to u and no outgoing edge from v, if this situation had occurred then S would not have been the longest path
// => indegree(u) = 0 and outdegree(v) = 0

// Algorithm: Steps involved in finding the topological ordering of a DAG:
// Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.

// Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

// Step-3: Remove a vertex from the queue (Dequeue operation) and then.

// Increment count of visited nodes by 1.
// Decrease in-degree by 1 for all its neighboring nodes.
// If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
// Step 5: Repeat Step 3 until the queue is empty.




// Step 5: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.

// How to find in-degree of each node?
// There are 2 ways to calculate in-degree of every vertex:

// Take an in-degree array which will keep track of
// Traverse the array of edges and simply increase the counter of the destination node by 1.
// for each node in Nodes
//     indegree[node] = 0;
// for each edge(src, dest) in Edges
//     indegree[dest]++
// Time Complexity: O(V+E)

// Traverse the list for every node and then increment the in-degree of all the nodes connected to it by 1.
//     for each node in Nodes
//         If (list[node].size()!=0) then
//         for each dest in list
//             indegree[dest]++;
// Time Complexity: The outer for loop will be executed V number of times and the inner for loop will be executed E number of times, Thus overall time complexity is O(V+E).

// The overall time complexity of the algorithm is O(V+E)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> topOrder(int n, vector<vector<int>>& adjlist) {

	queue<int> q;
	vector<int> toporder;
	vector<int> indeg(n, 0);
	int count = 0;
	for (int i = 0; i < adjlist.size(); ++i) {
		for (auto j : adjlist[i]) {
			indeg[j] += 1;
		}
	}

	for (int i = 0; i < indeg.size(); ++i) {
		if (indeg[i] == 0) {
			// cout << i << "\n";
			q.push(i);
		}
	}
	while (q.empty() == false) {
		int curr = q.front();
		// cout << curr << " curr " << "\n";
		q.pop();
		count += 1;
		toporder.push_back(curr);
		for (auto i : adjlist[curr]) {
			if (--indeg[i] == 0) {
				q.push(i);
			}
		}
	}
	if (count == n) {
		reverse(toporder.begin(), toporder.end());
		return toporder;
	}
	return {};
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> adjlist(n);
	int q, a, b;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> a >> b;
		adjlist[a].push_back(b);
	}
	vector<int> toporder;
	toporder = topOrder(n, adjlist);
	for (auto i : toporder) {
		cout << i << " ";
	}
	cout << "\n";
	return 0;
}