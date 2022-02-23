#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int missingNumber(vector<int> nums) {
	int result = nums.size(); 

	for (int i = 0; i < nums.size(); ++i) {
		result ^= nums[i] ^ i;
	}

	return result;
}

int missingNumberAlt(vector<int> nums){
	int result = nums.size();

	for (int i = 0; i < nums.size(); ++i) {
		result += (i - nums[i]);
	}

	return result;
}

int main () {
	vector<vector<int>> testCases = {
		{3,0,1},
		{0,1},
		{9,6,4,2,3,5,7,0,1}
	};

	for (auto test : testCases) {
		cout << missingNumberAlt(test) << endl;
	}
	
	return 0;
}