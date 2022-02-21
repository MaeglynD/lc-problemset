#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> threeSum(vector<int> nums) {
	vector<vector<int>> sums;

	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); ++i) {
		int a = nums[i];

		if (a > 0) {
			break;
		}

		if (i > 0 && nums[i -1] == nums[i]){
			continue;
		}

		int lptr = i+1;
		int rptr = nums.size()-1;

		int prevL = nums[0]-1;
		int prevR = nums[nums.size()-1]+1;

		while (lptr < rptr) {
			int b = nums[lptr];
			int c = nums[rptr];

			if (b == prevL) {
				lptr++;
				continue;
			}

			if (c == prevR) {
				rptr--;
				continue;
			}

			int abc = a + b + c;

			if (abc == 0) {
				sums.push_back({ a, b, c });
			}

			if (abc > 0) {
				rptr--;
				prevR = c;
			} else {
				lptr++;
				prevL = b;
			}
		}
	}

	return sums;
}

int main () {
	
	vector<vector<int>> testCases = {
		{1,-1,-1,0},
		{0, 0, 0},
		{-1,0,1,2,-1,-4},
		{},
		{0}, 
	};

	for (auto& test : testCases) {
		auto result = threeSum(test);

		for (auto x : result) {
			for (auto y : x) {
				cout << y << ", ";
			}

			cout << endl;
		}

		cout << endl;
	}

	return 0;
}
