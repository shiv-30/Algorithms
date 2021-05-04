// Maximum Sum Increasing Subsequence | DP-14
// Difficulty Level : Medium
//  Last Updated : 04 Apr, 2019
// Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the integers in the subsequence are sorted in increasing order. For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) and if the input array is {10, 5, 4, 3}, then output should be 10

// Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.

// Solution
// This problem is a variation of standard Longest Increasing Subsequence (LIS) problem. We need a slight change in the Dynamic Programming solution of LIS problem. All we need to change is to use sum as a criteria instead of length of increasing subsequence.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// TIme - O(n^2)
// SPace - O(n)
int MSIS(vector<int> arr, int n) {
    vector<int> l = arr;
    int maxm = INT_MIN;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i] && l[i] <= (arr[i] + l[j])) {
                l[i] = arr[i] + l[j];
            }
        }
    }
    int maxm = INT_MIN;
    for (int i = 0; i < n; ++i) {
        maxm = max(l[i], maxm);
    }
    return maxm;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << MSIS(v, n) << "\n";
    return 0;
}