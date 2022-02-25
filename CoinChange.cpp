#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int coinChange(vector<int> coins, int amount) {
	vector<int>DP(amount+1, amount+1);
	
	DP[0] = 0;

	for (int i = 1; i <= amount; ++i) {
		for (int coin : coins) {
			if (i - coin >= 0) {
				DP[i] = min(DP[i], 1 + DP[i - coin]);
			}
		}
	}

	return DP[amount] == amount+1 ? -1 : DP[amount];
}

int main () {
	vector<pair<vector<int>, int>> testCases = {
		{ {1, 2, 5}, 11 },
		{ {2}, 3 },
		{ {1}, 0 },
		{ {1}, 1 },
		{ {186, 419, 83, 408}, 6249 }
	};
	
	for (auto& [x, y] : testCases) {
		cout << coinChange(x, y) << endl;
	}
		
	return 0;
}