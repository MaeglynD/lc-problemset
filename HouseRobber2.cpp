#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int checkHouses(vector<int> &nums, bool alt) {
	int a = 0, b = 0;

	for (int i = alt; i < nums.size() - !alt; ++i) {
		int tmp = max(nums[i] + a, b);
		a = b;
		b = tmp;
	}
	
	return b;
}

int rob(vector<int> nums) {
	if (nums.size() == 1) {
		return nums[0];
	}

	return max(checkHouses(nums, 0), checkHouses(nums, 1));
}

int main () {
	vector<vector<int>> testCases = {
		{2,3,2},
		{1,2,3,1}
	};

	for (auto& test : testCases) {
		cout << rob(test) << endl;
	}

	return 0;
}
