#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> countBits(int n) {
	vector<int> results(n+1, 0);

	for (int i = 1; i < n+1; ++i) {
		results[i] = results[i >> 1] + i % 2;
	}

	return results;
}

int main () {
	vector<int> testCases = {2, 16};

	for (auto test : testCases) {
		vector<int> result = countBits(test);

		cout << test << " -- ";

		for (auto& x : result) {
			cout << x << ",  ";
		}

		cout << endl;
	}
	
	return 0;
}