// Target Sum
// ----------
// Given a set of non - negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

// Example:

// Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
// Output: True
// There is a subset (4, 5) with sum 9.

// Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
// Output: False
// There is no subset that add up to 30.

// Complexity Analysis:

// Time Complexity: O(sum*n), where sum is the ‘target sum’ and ‘n’ is the size of array.
// Auxiliary Space: O(sum*n), as the size of 2-D array is sum*n.
// Subset Sum Problem in O(sum) space
/*Om Namah Shivay*/
#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define f(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,n) f(i,0,n)
#define rrep(i,n) rf(i,n-1,0)
#define w(t) int t; cin>>t; while(t--)
#define vi vector<int>
#define vc vector<char>
#define vp vector<pair<int,int>>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define mii map<int,int>
#define omi unordered_map<int,int>
#define mci map<char,int>
#define mmi multimap<int,int>
#define inf (int)(1e18)
#define endl "\n"
#define print_m for(auto it:m){cout<<it.ff<<" "<<it.ss<<endl;}
#define print_v for(auto it:v){cout<<it<<" ";}
#define vvi  vector<vi>
#define pq             priority_queue<int>
#define pqr             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define gcd(a, b)       __gcd(a,b)

using namespace std;


void sosmart()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
// int dfs(vector<int> &adj, vector<int> &visited, int src, int count, int height) {
// 	visited[src] = true;
// 	height = max(count, height);
// for(int i = 0; i < adj[src].size(); ++i) {
// 	if(visited[adj[src][i]] == false) {
// 		dfs(adj, visited, adj[src][i], count+1);
// 	}
// }

// return height;
// }

vi p(1000006, 1);
vi prime;
void seive() {
	for (int i = 2; i < 1000006; i++) {
		if (p[i]) {
			prime.pb(i);
			for (int j = i * i; j <= 1000006; j = j + i) {
				p[j] = 0;
			}
		}
	}

}

bool targetSum(vi &v, vi &dp, int tsum, int n) {
	if (n == 0) {
		return 0;
	}
	else if (tsum == 0) {
		return 1;
	}
	else if (dp[n] != -1) {
		return dp[n];
	}
	else if (tsum < v[n - 1]) {
		return targetSum(v, dp, tsum, n - 1);
	}

	else {
		return dp[n] = targetSum(v, dp, tsum - v[n - 1], n - 1) || targetSum(v, dp, tsum, n - 1);
	}
}

int32_t main()
{
	sosmart();

	int n, tsum;
	cin >> n >> tsum;
	vi v(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	// vvi dp(m + 1, vi(n + 1, -1));
	vi dp(n + 1, -1);
	cout << targetSum(v, dp, tsum, n) << "\n";





	// end of code


	return 0;
}