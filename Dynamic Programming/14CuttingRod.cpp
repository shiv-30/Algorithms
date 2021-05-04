#include <iostream>
#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;

int maxProfit(vi &cost, vvi &dp, int totallen) {
	if (totallen == 0) {
		return 0;
	}
	else if (dp[totallen] == -1) {
		return dp[totallen];
	}
	int max_profit = 0;
	for (int i = 0; i <= totallen / 2; ++i) {
		max_profit = max(max_profit, maxProfit(cost, dp, i) + cost[totallen - i]);
	}
	return dp[totallen] = max_profit;
}

int main() {
	int totallen;
	cin >> totallen;
	int n;
	cin >> n;
	vi cost(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
	}
	vi dp(totallen + 1, -1);
	cout << maxProfit(cost, dp, totallen) << "\n";
	return 0;
}