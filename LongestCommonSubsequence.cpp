#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int longestCommonSubsequence(string a, string b) {
	int x = b.size(), y = a.size();
	int matrix[y][x];

	for (int i = y-1; i >= 0; --i) {
		for (int j = x-1; j >= 0; --j) {
			matrix[i][j] = 0;

			bool right = j+1 < x;
			bool down = i+1 < y;

			if (a[i] == b[j]) {
				matrix[i][j] = 1;

				if (right && down) {
					matrix[i][j] += matrix[i+1][j+1];
				}
			} else {
				if (right) {
					matrix[i][j] = matrix[i][j+1];
				}

				if (down) {
					matrix[i][j] = max(matrix[i][j], matrix[i+1][j]);
				} 
			} 
		}
	}

	return matrix[0][0];
}

int main () {
	vector<pair<string, string>> testCases = {
		{ "abcde", "ace" },
		{ "abc", "abc" },
		{ "abc", "def" }
	};

	for (auto& [a, b] : testCases) {
		cout << longestCommonSubsequence(a, b) << endl;
	}

	return 0;
}
