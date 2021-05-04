// Find the maximum and minimum element in an array
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
	// T - O(n)
	int mx = arr[0];
	int mn = arr[0];
	for (int i = 1; i < n; ++i) {
		mx = max(mx, arr[i]);
		mn = min(mn, arr[i]);
	}

	cout << "max = " << mx << " min = " << mn;
	return ;
}


void approach2(int a[], int n) {
	// T - O(nlogn)
	sort(a, a + n);
	cout << "max = " << a[n - 1] << " min = " << a[0];
	return ;

}

typedef struct Pair {
	int mx;
	int mn;
} Pair;

Pair recurse(int a[], int low, int high) {
	Pair minmax;
	if (low == high) {
		minmax.mn = minmax.mx =  a[low];
		return minmax;
	}
	else if (low + 1 == high) {
		minmax.mx = max(a[low], a[high]);
		minmax.mn = min(a[low], a[high]);
		return minmax;
	}
	else {

		int mid = low + (low + high) / 2;
		Pair mxmn = recurse(a, low, mid);
		minmax = recurse(a, mid + 1, high);
		minmax.mx = max(minmax.mx, mxmn.mx);
		minmax.mn = min(minmax.mn, mxmn.mn);
		return minmax;


	}
}
void approach3(int a[], int n) {
	// T - O(n)
	int low = 0;
	int high = n - 1;
	int mx = a[0];
	int mn = a[0];
	Pair minmax = recurse(a, low, high);
	cout << "max = " << minmax.mx << " min = " << minmax.mn;
	return;
}

int main() {

	c_p_c();
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	approach3(arr, n);

	// for (auto it : arr) {
	//     cout << it << " ";
	// }

	cout << "\n";

	return 0;


}