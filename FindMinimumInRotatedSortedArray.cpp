#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int findMin(vector<int> nums) {
	int minNum, lptr = 0, rptr = nums.size() -1;

	while(lptr <= rptr) {
		if (nums[lptr] <= nums[rptr]) {
			minNum = nums[lptr];
			break;
		}

		int mid = rptr - ((rptr - lptr) / 2);

		if (nums[mid] < nums[rptr])	{
			rptr = mid;
		} else {
			lptr = mid;
		}
	}

	return minNum;
}

int main () {
	vector<vector<int>> testCases = {
		{3,4,5,1,2},
		{4,5,6,7,0,1,2},
		{11,13,15,17}
	};
	
	for (auto& test : testCases) {
		cout << findMin(test) << endl;
	}
	return 0;
}
