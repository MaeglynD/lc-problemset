#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getSum(int a, int b) {
	while (b != 0) {
		unsigned tmp = (a & b);
		a = a ^ b;
		b = tmp << 1;
	}

	return a;
}

int main () {
	vector<pair<int, int>> testCases = {
		{1,2},
		{2,3},
		{-1, 1}
	};

	for (auto& [a, b] : testCases) {
		cout << getSum(a, b) << endl;
	}

	return 0;
}