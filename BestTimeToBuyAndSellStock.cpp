#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxProfit(vector<int>& prices) {
	int profit = 0;
	int minBuyPrice = INT_MAX;

	for (int i = 0; i < prices.size(); ++i) {
		if (prices[i] < minBuyPrice) {
			minBuyPrice = prices[i];
		} else {
			profit = max(profit, prices[i] - minBuyPrice);
		}
	}

	return profit;
}

int main () {
	vector<vector<int>> testCases = {
		{7, 1, 5, 3, 6, 4},
		{7, 6, 4, 3, 1}
	};

	for (auto& test : testCases) {
		cout << endl << maxProfit(test);
	}

	return 0;
}
