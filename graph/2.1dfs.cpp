#include <iostream>
#include <vector>
#include <list>
#include <bits/stdc++.h>
using namespace std;

class Graph {
	int totalv;
	list<int> *adjv;
	bool *visited;
	public:
	    Graph(int n) {
		    totalv = n;
		    adjv = new list<int> [totalv];
		    visited = new bool [totalv];
	    }
	    void addedge(int src, int dest) {
		    adjv[src].push_back(dest);
	    }
	    void dfs(int src) {
		    visited[src] = true;
		    cout << src << " " << "->";
		    list<int> adj = adjv[src];
		    list<int>::iterator it = adj.begin();
		    for(; it != adj.end(); ++it) {
			    if(visited[*it]==false) {
				    dfs(*it);
			    }
		    }
	    }
    void del() {
	       delete[] visited;
	       for(int i = 0; i < totalv; ++i) {
	           adjv[i].clear();
	       }
	   }	  
};
int main() {
	// total no of vertices
	int n;
	cin >> n;
	Graph g(n);
	// total no of queries
	int q;
	int src, dest;
	cin>> q;
	for(int i = 0; i < q; ++i) {
		cin >> src >> dest;
		g.addedge(src, dest);
	}
	//enter starting vertex
	cin >> src;
	g.dfs(src);
 	g.del();
	return 0;
}