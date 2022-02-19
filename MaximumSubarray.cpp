#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxSubarray(vector<int> nums) {
	int maxSub = nums[0], prefix = nums[0];

	for (int i = 1; i < nums.size(); ++i) {
		if (prefix < 0) {
			prefix = nums[i];
		} else {
			prefix += nums[i];
		}

		maxSub = max(maxSub, prefix);
	}

	return maxSub;
}

int main () {
	vector<vector<int>> testCases = {
		{-2,1,-3,4,-1,2,1,-5,4},
		{1},
		{5,4,-1,7,8}
	};

	for (auto& test : testCases) {
		cout << maxSubarray(test) << endl;
	}

	return 0;
}
