// 886. Possible Bipartition

// Medium

// 1202

// 33

// Add to List

// Share
// Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

// Each person may dislike some other people, and they should not go into the same group.

// Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

// Return true if and only if it is possible to split everyone into two groups in this way.



// Example 1:

// Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: group1 [1,4], group2 [2,3]
// Example 2:

// Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
// Example 3:

// Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// Output: false


// Constraints:

// 1 <= N <= 2000
// 0 <= dislikes.length <= 10000
// dislikes[i].length == 2
// 1 <= dislikes[i][j] <= N
// dislikes[i][0] < dislikes[i][1]
// There does not exist i != j for which dislikes[i] == dislikes[j].

bool isBipartite(vector<vector<int>>& adjlist, vector<bool>& visited, vector<int>& color, int n, int src) {
    queue<int> q;
    q.push(src);
    color[src] = 1;

    while (q.empty() == false) {
        src = q.front();
        visited[src] = true;
        q.pop();
        int clr = color[src];
        for (int i = 0; i < adjlist[src].size(); ++i) {
            if (color[adjlist[src][i]] == -1) {
                color[adjlist[src][i]] = 1 - clr;
                visited[adjlist[src][i]] = true;
                q.push(adjlist[src][i]);
            }
            else if (color[adjlist[src][i]] == clr) {
                return false;
            }
        }

    }
    // for(int i = 0; i < color.size(); ++i) {
    //     cout << i << " " << color[i] << "\n";
    // }
    return true;
}

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> adjlist(n);
    vector<bool> visited(n, false);
    vector<int> color(n, -1);
    int a, b;
    if (n == 1 or n == 0)
        return true;
    for (int i = 0; i < dislikes.size(); ++i) {
        a = dislikes[i][0] - 1;
        b = dislikes[i][1] - 1;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    // for(int i = 0; i < adjlist.size(); ++i) {
    //     cout << i ;
    //     for(int j = 0; j < adjlist[i].size(); ++j) {
    //         cout << " -> " << adjlist[i][j];
    //     }
    //     cout << "\n";
    // }
    bool partite = true;


    for (int j = 0; j < visited.size(); ++j) {
        if (visited[j] == false) {
            partite = partite && isBipartite(adjlist, visited, color, n, j);
        }
    }

    return partite;
    // return true;
}


int main() {
    int n;
    cin >> n;
    int a, b;
    int q;
    cin >> q;
    vector<vector<int>> dislikes(q, vector<int> (2, 0));
    for (int i = 0; i < q; ++i) {
        cin >> dislikes[i][0] >> dislikes[i][1];
    }
    cout << possibleBipartition(n, dislikes) << "\n";
    return 0;
}