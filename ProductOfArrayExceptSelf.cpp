#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> productOfArrayExceptSelf(vector<int> nums) {
	int postfix = 1;
	vector<int> products = nums;

	for (int i = 1; i < nums.size(); ++i) {
		products[i] *= products[i -1]; 
	}

	for (int i = nums.size() -1; i > 0; --i) {
		products[i] = postfix * products[i -1];
		postfix *= nums[i];
	}

	products[0] = postfix;

	return products;
}

int main () {
	vector<vector<int>> testCases = {
		{1,2,3,4},
		{-1,1,0,-3,3},
		{4,3,2,1,2}
	};

	for (auto& test : testCases) {
		auto result = productOfArrayExceptSelf(test);
	
		for (int& x : result) {
			cout << x << ", ";
		}

		cout << endl;
	}

	return 0;
}
