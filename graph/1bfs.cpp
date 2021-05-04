/*
input
5
7
0 1
0 4
1 2
1 3
1 4
2 3
3 4
0

output
0 -> 1 -> 4 -> 2 -> 3 -> 
*/
#include <iostream>
#include <queue>
#include <deque>
typedef long long ll;
using namespace std;
void addedge(vector<ll> adjlist[], ll a, ll b) {
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
}
void bfs(vector<ll> adjlist[], vector<bool> &visited, ll n, ll src) {
    queue<ll> q;
    q.push(src);
    ll top;
    visited[src] = true;
    while(q.empty()==false) {
        top = q.front();
        cout << top << " -> ";
        q.pop();
        
        for(ll i = 0; i < adjlist[top].size(); ++i) {
            if(visited[adjlist[top][i]] == false) {
                q.push(adjlist[top][i]);
                visited[adjlist[top][i]] = true;
            }
        }
    }
    
}
int main() {
    ll n;
    cin >> n;
    vector<ll> adjlist[n];
    vector<bool> visited(n, false);
    ll q, a, b;
    cin >> q;
    for(ll i = 0; i < q; ++i) {
        cin >> a >> b;
        addedge(adjlist, a, b);
    }
    ll src;
    cin >> src;
    bfs(adjlist, visited, n, src);
    return 0;
    
}