// Longest Increasing Subsequence | DP-3
// Difficulty Level : Medium
//  Last Updated : 18 May, 2020
// We have already discussed Overlapping Subproblems and Optimal Substructure properties.

// Now, let us discuss the Longest Increasing Subsequence (LIS) problem as an example problem that can be solved using Dynamic Programming.
// The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.
// longest-increasing-subsequence

// Examples:

// Input: arr[] = {3, 10, 2, 1, 20}
// Output: Length of LIS = 3
// The longest increasing subsequence is 3, 10, 20

// Input: arr[] = {3, 2}
// Output: Length of LIS = 1
// The longest increasing subsequences are {3} and {2}

// Input: arr[] = {50, 3, 10, 7, 40, 80}
// Output: Length of LIS = 4
// The longest increasing subsequence is {3, 7, 40, 80}
// Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.



// Method 1: Recursion.

// Optimal Substructure: Let arr[0..n-1] be the input array and L(i) be the length of the LIS ending at index i such that arr[i] is the last element of the LIS.




// Then, L(i) can be recursively written as:

// L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or
// L(i) = 1, if no such j exists.
// To find the LIS for a given array, we need to return max(L(i)) where 0 < i < n.

// Formally, the length of the longest increasing subsequence ending at index i, will be 1 greater than the maximum of lengths of all longest increasing subsequences ending at indices before i, where arr[j] < arr[i] (j < i). Thus, we see the LIS problem satisfies the optimal substructure property as the main problem can be solved using solutions to subproblems. The recursive tree given below will make the approach clearer:

// Input  : arr[] = {3, 10, 2, 11}
// f(i): Denotes LIS of subarray ending at index ‘i’

// (LIS(1)=1)

//       f(4)  {f(4) = 1 + max(f(1), f(2), f(3))}
//   /    |    \
// f(1)  f(2)  f(3) {f(3) = 1, f(2) and f(1) are > f(3)}
//        |      |  \
//       f(1)  f(2)  f(1) {f(2) = 1 + max(f(1)}
//               |
//             f(1) {f(1) = 1}
// Complexity Analysis:

// Time Complexity: O(n^2).
// As nested loop is used.
// Auxiliary Space: O(n).
// Use of any array to store LIS values at each index.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(m*n)
//space - O(n)
// Approach - dp
int LIS(vector<int> arr, int n) {
    vector<int> l(n, 1);
    int maxm = INT_MIN;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i] && l[i] <= l[j]) {
                l[i] = 1 + l[j];
            }
        }
        maxm = max(l[i], maxm);
    }
    return maxm;
}

int LIS(vector<int> arr, int n) {
    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
        int maxL = 0;
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                maxL = max(maxL, dp[j]);
            }
        }
        dp[i] = maxL + 1;
    }
    return *max_element(dp.begin(), dp.end());
}
// Time COmplexity - O(m*n)
// Space Comp - O(m*n)
int LIS(vector<int> &v, int m, int n, vector<vector<int>> &dp) {
    if (m == 0 or n == 0) {
        return 1;
    }
    else if (dp[m][n] != -1) {
        return dp[m][n];
    }
    else if (m < n && v[m - 1] < v[n - 1]) {
        return dp[m][n] = 1 + LIS(v, m - 1, n - 1, dp);
    }
    else if (n < m && v[n - 1] < v[m - 1]) {
        return dp[m][n] = 1 + LIS(v, m - 1, n - 1, dp);
    }
    else {
        return dp[m][n] = max(LIS(v, m - 1, n, dp), LIS(v, m, n - 1, dp));
    }
}

int main() {
    int m, n;
    cin >> n;
    m = n;
    vector<int> v(m, 0);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));


    cout << LIS(v, m, n, dp) << "\n";
}