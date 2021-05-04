// Longest Common Subsequence | DP-4
// Difficulty Level : Medium
//  Last Updated : 30 Sep, 2019
// We have discussed Overlapping Subproblems and Optimal Substructure properties in Set 1 and Set 2 respectively. We also discussed one example problem in Set 3. Let us discuss Longest Common Subsequence (LCS) problem as one more example problem that can be solved using Dynamic Programming.

// LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.

// In order to find out the complexity of brute force approach, we need to first know the number of possible different subsequences of a string with length n, i.e., find the number of subsequences with lengths ranging from 1,2,..n-1. Recall from theory of permutation and combination that number of combinations with 1 element are nC1. Number of combinations with 2 elements are nC2 and so forth and so on. We know that nC0 + nC1 + nC2 + … nCn = 2n. So a string of length n has 2n-1 different possible subsequences since we do not consider the subsequence with length 0. This implies that the time complexity of the brute force approach will be O(n * 2n). Note that it takes O(n) time to check if a subsequence is common to both the strings. This time complexity can be improved using dynamic programming.

// It is a classic computer science problem, the basis of diff (a file comparison program that outputs the differences between two files), and has applications in bioinformatics.

// Examples:
// LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
// LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

// Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.


// The naive solution for this problem is to generate all subsequences of both given sequences and find the longest matching subsequence. This solution is exponential in term of time complexity. Let us see how this problem possesses both important properties of a Dynamic Programming (DP) Problem.

// 1) Optimal Substructure:
// Let the input sequences be X[0..m-1] and Y[0..n-1] of lengths m and n respectively. And let L(X[0..m-1], Y[0..n-1]) be the length of LCS of the two sequences X and Y. Following is the recursive definition of L(X[0..m-1], Y[0..n-1]).

// If last characters of both sequences match (or X[m-1] == Y[n-1]) then
// L(X[0..m-1], Y[0..n-1]) = 1 + L(X[0..m-2], Y[0..n-2])

// If last characters of both sequences do not match (or X[m-1] != Y[n-1]) then
// L(X[0..m-1], Y[0..n-1]) = MAX ( L(X[0..m-2], Y[0..n-1]), L(X[0..m-1], Y[0..n-2]) )

// Examples:
// 1) Consider the input strings “AGGTAB” and “GXTXAYB”. Last characters match for the strings. So length of LCS can be written as:
// L(“AGGTAB”, “GXTXAYB”) = 1 + L(“AGGTA”, “GXTXAY”)
// longest-common-subsequence
// 2) Consider the input strings “ABCDGH” and “AEDFHR. Last characters do not match for the strings. So length of LCS can be written as:
// L(“ABCDGH”, “AEDFHR”) = MAX ( L(“ABCDG”, “AEDFHR”), L(“ABCDGH”, “AEDFH”) )

// So the LCS problem has optimal substructure property as the main problem can be solved using solutions to subproblems.

// 2) Overlapping Subproblems:
// Following is simple recursive implementation of the LCS problem. The implementation simply follows the recursive structure mentioned above.
// Time complexity of the above naive recursive approach is O(2^n) in worst case and worst case happens when all characters of X and Y mismatch i.e., length of LCS is 0.
// Considering the above implementation, following is a partial recursion tree for input strings “AXYT” and “AYZX”

//                          lcs("AXYT", "AYZX")
//                        /
//          lcs("AXY", "AYZX")            lcs("AXYT", "AYZ")
//          /                              /
// lcs("AX", "AYZX") lcs("AXY", "AYZ")   lcs("AXY", "AYZ") lcs("AXYT", "AY")
// In the above partial recursion tree, lcs(“AXY”, “AYZ”) is being solved twice. If we draw the complete recursion tree, then we can see that there are many subproblems which are solved again and again. So this problem has Overlapping Substructure property and recomputation of same subproblems can be avoided by either using Memoization or Tabulation. Following is a tabulated implementation for the LCS problem.
// filter_none
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


// TIme Complexity - O(m*n) SPace Complexity - O(n)
// Space optimized C++ implementation
// of LCS problem
#include<bits/stdc++.h>
using namespace std;

// Returns length of LCS
// for X[0..m-1], Y[0..n-1]
int lcs(string &X, string &Y)
{

    // Find lengths of two strings
    int m = X.length(), n = Y.length();

    int L[2][n + 1];

    // Binary index, used to
    // index current row and
    // previous row.
    bool bi;

    for (int i = 0; i <= m; i++)
    {

        // Compute current
        // binary index
        bi = i & 1;

        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[bi][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[bi][j] = L[1 - bi][j - 1] + 1;

            else
                L[bi][j] = max(L[1 - bi][j],
                               L[bi][j - 1]);
        }
    }

    // Last filled entry contains
    // length of LCS
    // for X[0..n-1] and Y[0..m-1]
    return L[bi][n];
}
// Time Complexity of the above implementation is O(mn) which is much better than the worst-case time complexity of Naive Recursive implementation.

// The above algorithm/code returns only length of LCS. Please see the following post for printing the LCS.

int LCS(string str1, string str2, int m, int n, vector<vector<int>> &dp) {
    if (m == 0 || n == 0) {
        return 0;
    }
    else if (dp[m][n] != -1) {
        return dp[m][n];
    }
    else if (str1[m - 1] == str2[n - 1]) {
        return dp[m][n] = 1 + LCS(str1, str2, m - 1, n - 1, dp);
    }
    else {
        return dp[m][n] = max(LCS(str1, str2, m - 1, n, dp), LCS(str1, str2, m, n - 1, dp));
    }
}

// PRINT LCS
string printLCS(vector<vector<int>> &dp, string str1, string str2, int m, int n, string & str) {
    if (m == 0 or n == 0 or dp[m][n] == -1) {
        return str;
    }
    else if (str1[m - 1] == str2[n - 1]) {
        str = str1[m - 1] + str;
        return printLCS(dp, str1, str2, m - 1, n - 1, str);
    }
    else {
        if (dp[m - 1][n] > dp[m][n - 1]) {
            return printLCS(dp, str1, str2, m - 1, n, str);
        }
        else {
            return printLCS(dp, str1, str2, m, n - 1, str);
        }
    }
}

int main() {
    string str1, str2, str = "";
    cin >> str1 >> str2;

    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
    cout << LCS(str1, str2, m, n, dp) << "\n";
    cout << printLCS(dp, str1, str2, m, n, str) << "\n";
    cout << lcs(str1, str2) << "\n";
    cout << "------------------------------------------" << "\n";
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}