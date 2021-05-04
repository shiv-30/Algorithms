// Longest subsequence such that difference between adjacents is one
// Difficulty Level : Easy
// Last Updated : 25 Mar, 2021
// Given an array of n size, the task is to find the longest subsequence such that difference between adjacents is one.

// Examples:

// Input :  arr[] = {10, 9, 4, 5, 4, 8, 6}
// Output :  3
// As longest subsequences with difference 1 are, "10, 9, 8",
// "4, 5, 4" and "4, 5, 6"

// Input :  arr[] = {1, 2, 3, 2, 3, 7, 2, 1}
// Output :  7
// As longest consecutive sequence is "1, 2, 3, 2, 3, 2, 1"
#include <bits/stdc++.h>
using namespace std;

#define int long long

void sosmart()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int LongestSubsequenceSuchThatDifferenceBetweenAdjacentIsone(vector<int> arr) {

	int n = arr.size();
	vector<int> dp(n, 0);
	dp[0] = 1;

	cout << arr[0] << " count " << dp[i] << "\n";

	for (int i = 1; i < n; ++i) {

		int maxn = 0;

		for (int j = 0; j < i; ++j) {

			if (abs(arr[i] - arr[j]) == 1 && maxn < dp[j]) {
				maxn = dp[j];
			}



		}
		dp[i] = maxn + 1;

		cout << arr[i] << " count " << dp[i] << "\n";


	}
	return *max_element(dp.begin(), dp.end());
}

signed  main() {

	sosmart();

	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << LongestSubsequenceSuchThatDifferenceBetweenAdjacentIsone(arr) << "\n";

	return 0;
}