#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool containsDuplicate(vector<int> nums) {
	unordered_set<int> records; 

	for (int& num : nums) {
		if (records.find(num) != records.end()) {
			return true;
		}

		records.insert(num);
	}

	return false;
}

int main () {
	vector<vector<int>> testCases = {
		{1,2,3,1},
		{1,2,3,4},
		{1,1,1,3,3,4,3,2,4,2}
	};

	for (auto& test : testCases) {
		cout << endl << containsDuplicate(test);
	}

	return 0;
}
