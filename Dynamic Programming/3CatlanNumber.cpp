// Catlan numbers
// c0 = 1
// c1 = 1
// c2 = c0c1 + c1c0 = 1 + 1 = 2

// cn = c0c(n - 1) + c0c(n - 2) + ..... + c(n - 2)c0 + c(n - 1)c0




//  Applications :
//  Number of possible Binary Search Trees with n keys.
//  Number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
//  Number of ways a convex polygon of n + 2 sides can split into triangles by connecting vertices.
//   convex
//  Number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n + 1 leaves.
// Number of different Unlabeled Binary Trees can be there with n nodes.
// The number of paths with 2n steps on a rectangular grid from bottom left, i.e., (n - 1, 0) to top right (0, n - 1) that do not cross above the main diagonal.
// 		     rectangle
// Number of ways to insert n pairs of parentheses in a word of n + 1 letters, e.g., for n = 2 there are 2 ways : ((ab)c) or (a(bc)). For n = 3 there are 5 ways, ((ab)(cd)), (((ab)c)d), ((a(bc))d), (a((bc)d)), (a(b(cd))).
// Number of noncrossing partitions of the set {1, …, 2n} in which every block is of size 2. A partition is noncrossing if and only if in its planar diagram, the blocks are disjoint (i.e. don’t cross). For example, below two are crossing and non - crossing partitions of {1, 2, 3, 4, 5, 6, 7, 8, 9} .  The partition {{1, 5, 7},  {2, 3, 8}, {4, 6}, {9}} is crossing and partition {{1, 5, 7}, {2, 3}, {4}, {6}, {8, 9}} is non - crossing.
// partitiom
// Number of Dyck words of length 2n. A Dyck word is a string consisting of n X’s and n Y’s such that no initial segment of the string has more Y’s than X’s.  For example, the following are the Dyck words of length 6: XXXYYY     XYXXYY     XYXYXY     XXYYXY     XXYXYY.
// Number of ways to tile a stairstep shape of height n with n rectangles. The following figure illustrates the case n = 4:
// stair
// Number of ways to connect the points on a circle disjoint chords.  This is similar to point 3 above.
// Number of ways to form a “mountain ranges” with n upstrokes and n down - strokes that all stay above the original line.The mountain range interpretation is that the mountains will never go below the horizon.Mountain_Ranges
// Number of stack - sortable permutations of {1, …, n} . A permutation w is called stack - sortable if S(w) = (1, …, n), where S(w) is defined recursively as follows: write w = unv where n is the largest element in w and u and v are shorter sequences, and set S(w) = S(u)S(v)n, with S being the identity for one - element sequences.
// 	        Number of permutations of {1, …, n} that avoid the pattern 123 ( or any of the other patterns of length 3); that is, the number of permutations with no three - term increasing subsequence. For n = 3, these permutations are 132, 213, 231, 312 and 321. For n = 4, they are 1432, 2143, 2413, 2431, 3142, 3214, 3241, 3412, 3421, 4132, 4213, 4231, 4312 and 4321
//                 /*Om Namah Shivay*/
#include <bits/stdc++.h>
#define int long long int
using namespace std;

// Recursive Solution
// Time - Exponential
// c(0) -> 0
// c(1) -> 1
// c(2) -> C(1) + C(0)  = 2
//                        C(3) -> 8
// A recursive function to find nth catalan number
int catalanNumberR(int n)
{
	// Base case
	if (n == 0 or n == 1) {
		return 1;
	}

	// catalan(n) is sum of
	// catalan(i)*catalan(n-i-1)

	int result = 0;

	for (int i = 0; i <= n - 1; ++i) {
		result += catalanNumberR(i) * catalanNumberR(n - 1 - i);
	}
	return result;
}


// Dynamic Programming (Memoization)
// Time Complexity - o(n^2)
int catalanNumberM(vector<int> &dp, int n) {
	if (n == 0 or n == 1) {
		return 1;
	}
	else if (dp[n] != -1) {
		return dp[n];
	}
	int result = 0;
	for (int i = 0; i < n; ++i) {
		result += catalanNumberM(dp, i) * catalanNumberM(dp, n - 1 - i);
	}


	return dp[n] = result;
}

// Dynamic Programming Tabulation
int catalanNumberT(int n) {
	if (n == 0 or n == 1) {
		return 1;
	}
	vector<int> dp(n + 1, 0);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = 0;
		for (int j = 0; j <= n - 1; ++j) {
			dp[i] += dp[j] * dp[n - 1 - j];
		}
	}
	return dp[n];
}

// A Binomial coefficient based function to find nth catalan
// number in O(n) time and O(1) space
int BCoeff(int n, int k) {
	// Since C(n, k) = C(n, n-k)
	if (k > n - k) {
		k = n - k;
	}
	int result = 1;
	// Calculate value of [n*(n-1)*---*(n-k+1)] /
	// [k*(k-1)*---*1]
	for (int i = 0; i < k; ++i) {
		result *= (n - i);
		result /= (i + 1);
	}
	return result;
}

// A Binomial coefficient based function to find nth catalan
// number in O(n) time and O(1) space
int catalanNumberBC(int n) {
	if (n == 0 or n == 1) {
		return 1;
	}
	// Calculate value of 2nCn
	int result = BCoeff(2 * n, n);
	// return 2nCn/(n+1)
	return result / (n + 1);
}
// Driver code
int32_t main()
{

	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);
	cout << catalanNumberM(dp, n) << "\n";
	return 0;
}
