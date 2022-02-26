#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int lengthOfLIS(vector<int> nums) {
	vector<int> mem(nums.size(), 0);
	int lis = 1;

	mem.back() = 1;

	for (int i = nums.size()-2; i >=0; --i) {
		int localLis = 1;

		for (int j = i+1; j < nums.size(); ++j) {
			if (nums[j] > nums[i]) {
				if (mem[j] != 0) {
					localLis = max(localLis, mem[j] +1);
				}
			}
		}

		mem[i] = localLis;
		lis = max(lis, localLis);
	}

	return lis;
}

int main () {
	vector<vector<int>> testCases = {
		{10,9,2,5,3,7,101,18},
		{0,1,0,3,2,3},
		{7,7,7,7,7,7,7}
	};

	for (auto& test : testCases) {
		cout << lengthOfLIS(test) << endl;
	}
	
	return 0;
}
