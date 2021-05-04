// Edit Distance | DP-5
// Difficulty Level : Medium
//  Last Updated : 02 Feb, 2021

// Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

// Insert
// Remove
// Replace
// All of the above operations are of equal cost.

// Examples:

// Input:   str1 = "geek", str2 = "gesek"
// Output:  1
// We can convert str1 into str2 by inserting a 's'.

// Input:   str1 = "cat", str2 = "cut"
// Output:  1
// We can convert str1 into str2 by replacing 'a' with 'u'.

// Input:   str1 = "sunday", str2 = "saturday"
// Output:  3
// Last three and first characters are same.  We basically
// need to convert "un" to "atur".  This can be done using
// below three operations.
// Replace 'n' with 'r', insert t, insert a
// Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.

// What are the subproblems in this case?
// The idea is process all characters one by one staring from either from left or right sides of both strings.
// Let us traverse from right corner, there are two possibilities for every pair of character being traversed.

// m: Length of str1 (first string)
// n: Length of str2 (second string)
// If last characters of two strings are same, nothing much to do. Ignore last characters and get count for remaining strings. So we recur for lengths m-1 and n-1.
// Else (If last characters are not same), we consider all operations on ‘str1’, consider all three operations on last character of first string, recursively compute minimum cost for all three operations and take minimum of three values.
// Insert: Recur for m and n-1
// Remove: Recur for m-1 and n
// Replace: Recur for m-1 and n-1
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

Time Complexity: O(m x n)
Auxiliary Space: O(m x n)

// Space Complex Solution: In the above-given method we require O(m x n) space. This will not be suitable if the length of strings is greater than 2000 as it can only create 2D array of 2000 x 2000. To fill a row in DP array we require only one row the upper row. For example, if we are filling the i = 10 rows in DP array we require only values of 9th row. So we simply create a DP array of 2 x str1 length.
// This approach reduces the space complexity. Here is the C++ implementation of the above-mentioned problem
void EditDistDP(string str1, string str2)
{
	int len1 = str1.length();
	int len2 = str2.length();

	// Create a DP array to memoize result
	// of previous computations
	int DP[2][len1 + 1];

	// To fill the DP array with 0
	memset(DP, 0, sizeof DP);

	// Base condition when second string
	// is empty then we remove all characters
	for (int i = 0; i <= len1; i++)
		DP[0][i] = i;

	// Start filling the DP
	// This loop run for every
	// character in second string
	for (int i = 1; i <= len2; i++) {
		// This loop compares the char from
		// second string with first string
		// characters
		for (int j = 0; j <= len1; j++) {
			// if first string is empty then
			// we have to perform add character
			// operation to get second string
			if (j == 0)
				DP[i % 2][j] = i;

			// if character from both string
			// is same then we do not perform any
			// operation . here i % 2 is for bound
			// the row number.
			else if (str1[j - 1] == str2[i - 1]) {
				DP[i % 2][j] = DP[(i - 1) % 2][j - 1];
			}

			// if character from both string is
			// not same then we take the minimum
			// from three specified operation
			else {
				DP[i % 2][j] = 1 + min(DP[(i - 1) % 2][j],
				                       min(DP[i % 2][j - 1],
				                           DP[(i - 1) % 2][j - 1]));
			}
		}
	}

	// after complete fill the DP array
	// if the len2 is even then we end
	// up in the 0th row else we end up
	// in the 1th row so we take len2 % 2
	// to get row
	cout << DP[len2 % 2][len1] << endl;
}

// Time Complexity: O(m x n)
// Auxiliary Space: O( m x n )
// Memoized Top-down Approach
int editDistance(string str1, string str2, vector<vector<int>> &dp, int m, int n) {
	if (m == 0) {
		return n;
	}
	else if (n == 0) {
		return m;
	}
	else if (dp[m][n] != -1) {
		return dp[m][n];
	}
	else if (str1[m - 1] == str2[n - 1]) { // if the characters are equal
		return dp[m][n] = editDistance(str1, str2, dp, m - 1, n - 1);
	}
	else {
		// Insert
		int insert = 1 + editDistance(str1, str2, dp, m, n - 1);
		// remove
		int remov = 1 + editDistance(str1, str2, dp, m - 1, n);
		// replace
		int replace = 1 + editDistance(str1, str2, dp, m - 1, n - 1);
		return dp[m][n] = min(insert, min(remov, replace));

	}
}

int main() {
	string str1, str2;
	str1 = "sunday";
	str2 = "saturday";
	int m = str1.length();
	int n = str2.length();
	vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
	cout << editDistance(str1, str2, dp, m, n) << "\n";
	return 0;
}