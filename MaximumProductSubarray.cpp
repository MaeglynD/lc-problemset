#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maximumProductSubarray(vector<int> nums) {
	int maxSub = nums[0], minP = nums[0], maxP = nums[0];

	for (int i = 1; i < nums.size(); ++i) {
		if (i == 0) {
			maxP = 1;
			minP = 1;
		} else {
			int a = minP * nums[i];
			int b = maxP * nums[i];

	 		// Replacing the initializer list syntax with just another set of max() and min()'s
			// turns the runtime from 20ms to 0ms. But it looks pretty so its here to stay
			minP = min({ nums[i], a, b });
			maxP = max({ nums[i], a, b });

			maxSub = max(maxSub, maxP);
		}
	}

	return maxSub;
}

int main () {
	vector<vector<int>> testCases = {
		{2,3,-2,4},
		{-2,0,-1}
	};

	for (auto& test : testCases) {
		cout << maximumProductSubarray(test) << endl;
	}

	return 0;
}
