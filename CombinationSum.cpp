#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void findCombinations(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& path, int& target, int total, int i) {
	if (total > target) {
		return;
	}	

	if (total == target) {
		ans.push_back(path);
		return; 
	}

	for (; i < candidates.size(); ++i) {
		path.push_back(candidates[i]);
		findCombinations(candidates, ans, path, target, total + candidates[i], i);
		path.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int> candidates, int target) {
	vector<vector<int>> ans; 
	vector<int> path;

	findCombinations(candidates, ans, path, target, 0, 0);
	
	return ans;
}

int main () {
	vector<pair<vector<int>, int>> testCases = {
		{ {2,3,6,7}, 7 },
		{ {2,3,5}, 8 },
		{ {2}, 1 },
		{ {2,7,6,3,5,1}, 9}
	};

	for (auto& [candidates, target] : testCases) {
		vector<vector<int>> result = combinationSum(candidates, target);

		cout << "[ ";

		for (auto x : result) {
			cout << "[ ";

			for (auto y : x) {
				cout << y << ", ";
			}

			cout << " ] " ;
		}

		cout << " ]" << endl;
	}

	return 0;
}


