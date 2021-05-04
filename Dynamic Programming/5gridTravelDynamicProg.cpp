// Grid Travelling:
// Problem Statement : Given a 2-D matrix with M rows and N columns,
// find the number of ways to reach cell with coordinates (i,j)
// from starting cell (0,0) under the condition that you can only travel
// one step right or one step down.
// Input:
// 3 3
// Output
// 6
/*Om Namah Shivay*/
// Only brute force
// O(2^(n+m)) time
// O(n+m) space

// memoized
// O(m*n) time
// O(m+n) space
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

int gridTraveler(vvi &dp, int m, int n) {
	if (m == 1 && n == 1) {
		return 1;
	}
	else if (m == 0 or n == 0) {
		return 0;
	}
	else if (dp[m][n] != -1) {
		return dp[m][n];
	}
	else {
		return dp[m][n] = gridTraveler(dp, m - 1, n) + gridTraveler(dp, m, n - 1);
	}
}

int32_t main()
{
	sosmart();

	int m, n;
	cin >> m >> n;
	vvi dp(m + 1, vi(n + 1, -1));
	cout << gridTraveler(dp, m, n) << "\n";





	// end of code


	return 0;
}