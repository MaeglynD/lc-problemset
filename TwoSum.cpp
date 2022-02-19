#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> twoSum(vector<int>nums, int target) {
	unordered_map<int, int> recordings;

	for(int i = 0; i < nums.size(); ++i) {
		int& num = nums[i];

		if (recordings.count(num)) {
			return { recordings[num], i };
		}

		recordings.insert({ target - num, i });
	}
};

int main () {
	vector<pair<vector<int>, int>> testCases = {
		{ {2,7,11,15}, 9 },
		{ {3, 2, 4}, 6 },
		{ {3, 3}, 6 },
		{ {-1, -2, -3, -4, -5}, -8 }
	};

	for (auto& [nums, target] : testCases) {
		vector<int> indices = twoSum(nums, target);

		cout << endl << indices[0] << " " << indices[1];
	}

	return 0;
}
