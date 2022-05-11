#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums){
	vector<int> mem;
	
	for (int i = 0; i < nums.size(); ++i){
		auto it = lower_bound(mem.begin(), mem.end(), nums[i]);

		if (it == mem.end()) {
			mem.push_back(nums[i]);
		} else {
			mem[it-mem.begin()] = nums[i];
		}
	}

	return mem.size();
}

int lengthOfLISAlt(vector<int>& nums){
	int ans = 1;
	int mem[nums.size()];

	for (int i = nums.size()-1; i >= 0; --i) {
		int tmp = 0;

		for (int j = i; j < nums.size(); ++j) {
			if (nums[j] > nums[i]) {
				tmp = max(tmp, mem[j]);
				
				if (tmp == ans)
					break;
			}
		}

		mem[i] = 1+tmp;
		ans = max(ans, mem[i]);
	}

	return ans;
}

int main(){
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
