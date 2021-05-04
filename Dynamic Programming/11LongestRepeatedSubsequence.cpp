// Longest Repeating Subsequence
// Difficulty Level : Medium
//  Last Updated : 03 Feb, 2021
// Given a string, find the length of the longest repeating subsequence such that the two subsequences don’t have same string character at the same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.


// longest-repeating-subsequence

// Examples:

// Input: str = "abc"
// Output: 0
// There is no repeating subsequence

// Input: str = "aab"
// Output: 1
// The two subssequence are 'a'(first) and 'a'(second).
// Note that 'b' cannot be considered as part of subsequence
// as it would be at same index in both.

// Input: str = "aabb"
// Output: 2

// Input: str = "axxxy"
// Output: 2
// Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
// This problem is just the modification of Longest Common Subsequence problem. The idea is to find the LCS(str, str)where str is the input string with the restriction that when both the characters are same, they shouldn’t be on the same index in the two strings.
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int LRS(string str1, string str2, vector<vector<int>> &dp, int m, int n) {
    if (m == 0 || n == 0) {
        return 0;
    }
    else if (dp[m][n] != -1) {
        return dp[m][n];
    }
    // If characters match and indexes are
    // not same
    else if (str1[m - 1] == str2[n - 1] && m != n) {
        return dp[m][n] = 1 + LRS(str1, str2, dp, m - 1, n - 1);
    }
    // If characters are not same
    else {
        return dp[m][n] = max(LRS(str1, str2, dp, m - 1, n), LRS(str1, str2, dp, m, n - 1));
    }
}

int main() {
    string str1, str2;
    cin >> str1;
    str2 = str1;
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int> (m + 1, -1));
    cout << LRS(str1, str2, dp, m, n) << "\n";
    return 0;
}