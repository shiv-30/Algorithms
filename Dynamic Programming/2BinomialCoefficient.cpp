// Binomial Coefficient | DP - 9

// The following are the common definitions of Binomial Coefficients.

// A binomial coefficient C(n, k) can be defined as the coefficient of x^k in the expansion of (1 + x)^n.

// A binomial coefficient C(n, k) also gives the number of ways, disregarding order, that k objects can be chosen from among n objects more formally, the number of k - element subsets ( or k - combinations) of a n - element set.

// The Problem
// Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k). For example, your function should return 6 for n = 4 and k = 2, and it should return 10 for n = 5 and k = 2.

//         Recommended : Please solve it on “PRACTICE” first, before moving on to the solution.
// 	        1) Optimal Substructure
// 	The value of C(n, k) can be recursively calculated using the following standard formula for Binomial Coefficients.




// 		C(n, k) = C(n - 1, k - 1) + C(n - 1, k)
// 		          C(n, 0) = C(n, n) = 1

// // This is code is contributed by rathbhupendra

// 		                              Value of C(5, 2) is 10
// 		                              2) Overlapping Subproblems
// 		It should be noted that the above function computes the same subproblems again and again. See the following recursion tree for n = 5 an k = 2. The function C(3, 1) is called two times. For large values of n, there will be many common subproblems.



// 			        Binomial Coefficients Recursion tree for C(5, 2)

// 				        Since the same subproblems are called again, this problem has Overlapping Subproblems property. So the Binomial Coefficient problem has both properties (see this and this) of a dynamic programming problem. Like other typical Dynamic Programming(DP) problems, re - computations of the same subproblems can be avoided by constructing a temporary 2D - array C[][] in a bottom - up manner. Following is Dynamic Programming based implementation.
//
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

// Time Complexity: O(n*k)
// Auxiliary Space: O(n*k)
int binomialCoefficient(vvi &dp, int n, int r) {
	if (r == 0 || n == r) {
		return 1;
	}
	else if (dp[n][r] != -1) {
		return dp[n][r];
	}

	else {
		return dp[n][r] = binomialCoefficient(dp, n - 1, r - 1) + binomialCoefficient(dp, n - 1, r);
	}
}

// Returns value of Binomial Coefficient C(n, k)
// Complexity Analysis:

// Time Complexity: O(r).
// A loop has to be run from 0 to r. So, the time complexity is O(r).
// Auxiliary Space: O(1).
// As no extra space is required.
int binomialCoefficient(int n, int k)
{
	int res = 1;

	// Since C(n, k) = C(n, n-k)
	if (k > n - k)
		k = n - k;

	// Calculate value of
	// [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
	for (int i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
}

int32_t main()
{
	sosmart();

	int n, r;
	cin >> n >> r;
	vvi dp(n + 1, vi(r + 1, -1));
	cout << binomialCoefficient(dp, n, r) << "\n";





	// end of code


	return 0;
}