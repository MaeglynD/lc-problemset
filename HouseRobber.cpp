#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 0ms
int rob(vector<int> nums) {
	int ans = INT_MIN;

	if (nums.size() == 1) return nums[0];
	if (nums.size() == 2) return max(nums[0], nums[1]);

	if (nums.size() > 2) {
		nums[2] += nums[0];
		ans = max(nums[1], nums[2]);
	}

	for (int i = 3; i < nums.size(); ++i) {
		nums[i] += max(nums[i-2], nums[i-3]);
		ans = max(ans, nums[i]);
	}

	return ans;
}

// 6ms
int robAlt(vector<int> nums) {
	int a = 0, b = 0;

	for (int& n : nums) {
		int tmp = max(a+n, b);
		a = b;
		b = tmp;
	}

	return b;
}

int main () {
	vector<vector<int>> testCases = {
		{1,2,3,1},
		{2,7,9,3,1}
	};

	for (auto& test : testCases) {
		cout << rob(test) << endl;
	}

	return 0;
}
