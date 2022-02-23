#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxArea(vector<int> height) {
	int maxTotal = 0, lptr = 0, rptr = height.size()-1;

	while (lptr < rptr) {
		maxTotal = max(maxTotal, min(height[lptr], height[rptr]) * (rptr - lptr));

		if (height[lptr] > height[rptr]) {
			rptr--;
		} else {
			lptr++;
		}
	}

	return maxTotal;
}

int main () {
	vector<vector<int>> testCases = {
		{1,8,6,2,5,4,8,3,7},
		{1, 1}
	};

	for (auto& test : testCases) {
		cout << maxArea(test) << endl;
	}

	return 0;
}
