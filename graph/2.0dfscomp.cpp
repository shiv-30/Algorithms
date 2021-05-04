//for unweighted graph
/*
	intput
	5 //no of vertices
	7 //no of queries of edges
	0 1 
	0 4
	1 2
	1 3
	1 4
	2 3
	3 4
	0 // starting vertex for dfs

	output
	0 -> 1 -> 2 -> 3 -> 4 
*/
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
typedef long long ll;
void addedge(vector<ll> graph[], ll a, ll b) {
	graph[a].push_back(b);
	graph[b].push_back(a);
}
void dfs(vector<ll> graph[], vector<bool> &visited, ll src) {
	visited[src] = true;
	cout << src << " -> ";
	for(ll i = 0; i < graph[src].size(); ++i) {
		if(visited[graph[src][i]] == false)
			dfs( graph, visited, graph[src][i]);
	}
}
int main() {
	ll n;
	cin >> n;
	vector<ll> graph[n];
	vector<bool> visited(n, false);
	ll q, a, b; // no of queries
	cin >> q;
	for(ll i = 0; i < q; ++i) {
		cin >> a >> b;
		addedge(graph, a, b);
	}
	//enter starting vertex
	cin >> a;
	dfs(graph, visited, a);

}