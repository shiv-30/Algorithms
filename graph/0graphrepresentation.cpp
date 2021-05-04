#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <array>
#include <math.h>
#include <string.h>
typedef long long ll;
using namespace std;

void file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
void addedge(vector<ll> graph[], ll a, ll b) {
	graph[a].push_back(b);
	graph[b].push_back(a);
}
void printgraph(vector<ll> graph[], ll n) {
	for(ll i = 0; i < n; ++i) {
		cout << "\n Adjacency list of vertex " << i << "\n head";
		for(auto x : graph[i]) {
			cout << "-> " << x;
		}
		cout << "\n";
	}
}
void deletegraph(vector<ll> graph[], ll n) {
	for(ll i = 0; i < n; ++i) {
		graph[i].clear();
	}
}
void solve()
{
	// write your code here
	ll n;
	 // cout << "no of vertices" << "\n";
	cin >> n;
	vector<ll> graph[n];
	ll q;
	ll a, b;
	 // cout << "\n Enter no of queries\n";
	cin >> q;
	for(ll i = 0; i < q; ++i) {
		cin >> a >> b;
		addedge(graph, a, b);
	}
	printgraph(graph, n);
	deletegraph(graph, n);
	

}
int main() {
	file();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	// ll t;
	// cin >> t;
	
	// while (t--) {
	solve();
	// }
	
	return 0;
}