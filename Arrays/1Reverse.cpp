// Reverse an array
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

void c_p_c()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


void reverse(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    swap(arr[start], arr[end]);
    return reverse(arr, start + 1, end - 1);
}
int main() {

    c_p_c();
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int start = 0, end = n - 1;

    // while (start < end ) {
    //     swap(arr[start], arr[end]);
    //     start++;
    //     end--;
    // }

    reverse(arr, 0, n - 1);

    for (auto it : arr) {
        cout << it << " ";
    }

    cout << "\n";

    return 0;


}