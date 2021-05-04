// 1319. Number of Operations to Make Network Connected
// Medium

// 647

// 13

// Add to List

// Share
// There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

// Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1.



// Example 1:



// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
// Example 2:



// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// Output: 2
// Example 3:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// Output: -1
// Explanation: There are not enough cables.
// Example 4:

// Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
// Output: 0


// Constraints:

// 1 <= n <= 10^5
// 1 <= connections.length <= min(n*(n-1)/2, 10^5)
// connections[i].length == 2
// 0 <= connections[i][0], connections[i][1] < n
// connections[i][0] != connections[i][1]
// There are no repeated connections.
// No two computers are connected by more than one cable.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count = 0;
int *ptr = &count;

// find Operation
int find(vector<int>& dsuf, int src) {
	if (dsuf[src] == -1) {
		return src;
	}
	return dsuf[src] = find(dsuf, dsuf[src]);
}

// Union Operation
void union_op(vector<int>& dsuf, int src, int dst) {
	int toP = find(dsuf, dst);
	int fromP = find(dsuf, src);
	if (toP == fromP) {
		*ptr += 1;
	}
	else {
		dsuf[toP] = fromP;
	}
	return;

}
int makeConnected(int n, vector<vector<int>>& conts) {
	vector<int> dsuf(n);
	for (int i = 0; i < n; ++i) {
		dsuf[i] = -1;
	}

	for (int i = 0; i < conts.size(); ++i) {
		union_op(dsuf, conts[i][0], conts[i][1]);
	}
	int node = 0;
	for (int i = 0; i < n; ++i) {
		if (dsuf[i] == -1) {
			node++;
		}
	}
	node--;
	if (node > *ptr) {
		return -1;
	}
	return node;

}


int main() {
	int V, E;
	cin >> V >> E;
	vector<int> conts[V];
	int a, b;
	for (int i = 0; i < E; ++i) {
		cin >> a >> b;
		conts[a].push_back(b);
	}
	cout << makeConnected(V, conts) << "\n";
	return 0;
}