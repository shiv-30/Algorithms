#include <bits/stdc++.h>
using namespace std;

#define int long long

void sosmart()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int MaximumSumSubsequenceSuchThatNoThreeAreConsecutive(vector<int> arr) {

	int n = arr.size();
	vector<int> sum(n, 0);
	sum[0] = arr[0];

	if (n == 1) {
		return arr[0];
	}
	else if (n == 2) {
		return arr[0] + arr[1];
	}
	else if (n == 3) {
		return max(arr[0] + arr[1], arr[1] + arr[2]);
	}

	sum[1] = arr[0] + arr[1];
	sum[2] = max(sum[1], arr[1] + arr[2]);

	for (int i = 3; i < n; ++i) {
		sum[i] = max(sum[i - 1], max(sum[i - 2] + arr[i], sum[i - 3] + arr[i - 1] + arr[i]));
	}



	return sum[n - 1];
}

signed  main() {

	sosmart();

	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << MaximumSumSubsequenceSuchThatNoThreeAreConsecutive(arr) << "\n";

	return 0;
}