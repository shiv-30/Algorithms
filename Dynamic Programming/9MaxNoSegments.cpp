// Maximize the number of segments of length p, q and r
// Difficulty Level : Medium
//  Last Updated : 10 Nov, 2020
// Given a rod of length L, the task is to cut the rod in such a way that the total number of segments of length p, q and r is maximized. The segments can only be of length p, q, and r.

// Examples:

// Input: l = 11, p = 2, q = 3, r = 5
// Output: 5
// Segments of 2, 2, 2, 2 and 3
// Input: l = 7, p = 2, q = 5, r = 5
// Output: 2
// Segments of 2 and 5

// Recommended: Please try your approach on {IDE} first, before moving on to the solution.
// Approach:

// As the solution for maximum number of cuts that can be made in a given length depends on the maximum number of cuts previously made in shorter lengths, this question could be solved by the approach of Dynamic Programming. Suppose we are given a length ‘l’. For finding the maximum number of cuts that can be made in length ‘l’, find number of cuts made in shorter previous length ‘l-p’,’l-q’,’l-r’ lengths respectively. The required answer would be the max(l-p,l-q,l-r)+1 as one more cut should be needed after this to cut length ‘l’. So for solving this problem for given length, find maximum number of cuts that can be made in lengths ranging from ‘1’ to ‘l’.




// Example:

// l = 11, p = 2, q = 3, r = 5
// Analysing lengths from 1 to 11:

// Not possible to cut->0
// Possible cut is of lengths 2->1 (2)
// Possible cut is of lengths 3->1 (3)
// Possible cuts are of lengths max(arr[4-2],arr[4-3])+1->2 (2,2)
// Possible cuts are of lengths max(arr[5-2],arr[5-3])+1->2 (2,3)
// Possible cuts are of lengths max(arr[6-2],arr[6-3],arr[6-5])+1->3 (2,2,2)
// Possible cuts are of lengths max(arr[7-2],arr[7-3],arr[7-5])+1->3 (2,3,2) or (2,2,3)
// Possible cuts are of lengths max(arr[8-2],arr[8-3],arr[8-5])+1->4 (2,2,2,2)
// Possible cuts are of lengths max(arr[9-2],arr[9-3],arr[9-5])+1->4 (2,3,2,2) or (2,2,3,2) or (2,2,2,3)
// Possible cuts are of lengths max(arr[10-2],arr[10-3],arr[10-5])+1->5 (2,2,2,2,2)
// Possible cuts are of lengths max(arr[11-2],arr[11-3],arr[11-5])+1->5 (2,3,2,2,2) or (2,2,3,2,2) or (2,2,2,3,2) or (2,2,2,2,3)
// Algorithm:

// Initialise an array DP[]={-1} and DP[0]=0.
// Run a loop from ‘1’ to ‘l’
// If DP[i]=-1 means it’s not possible to divide it using giving segments p,q,r so continue;
// DP[i+p]=max(DP[i+p],DP[i]+1)
// DP[i+q]=max(DP[i+q],DP[i]+1)
// DP[i+r]=max(DP[i+r],DP[i]+1)
// print DP[l]
// Pseudo Code:

// DP[l+1]={-1}
// DP[0]=0
// for(i from 0 to l)
//   if(DP[i]==-1)
//   continue
//   DP[i+p]=max(DP[i+p],DP[i]+1)
//   DP[i+q]=max(DP[i+q],DP[i]+1)
//   DP[i+r]=max(DP[i+r],DP[i]+1)

// print(DP[l])

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxNoSegments(int l, int p, int q, int r) {

    vector<int> dp(l + 1, -1);
    dp[l] = 0;
    for (int i = l; i >= 0; --i) {
        if (dp[i] == -1) {
            continue;
        }
        else {
            if (i - p >= 0) {
                dp[i - p] = max(dp[i - p], 1 + dp[i]);
            }
            if (i - q >= 0) {
                dp[i - q] = max(dp[i - q], 1 + dp[i]);
            }
            if (i - r >= 0) {
                dp[i - r] = max(dp[i - r], 1 + dp[i]);
            }

        }
    }
    return dp[0];
}

int main() {
    int l, p, q, r;
    cin >> l >> p >> q >> r;
    cout << maxNoSegments(l, p, q, r) << "\n";
    return 0;
}