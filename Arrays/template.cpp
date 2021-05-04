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

void approach1(int arr[], int n) {

}

int main() {

	c_p_c();
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	approach1(arr, n);

	for (auto it : arr) {
		cout << it << " ";
	}

	cout << "\n";

	return 0;


}