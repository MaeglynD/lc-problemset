#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getSum(int a, int b) {
	while (b > 0) {
		int tmp = (a & b) << 1;
		a = a ^ b;
		b = tmp;
	}

	return a;
}

int main () {
	vector<pair<int, int>> testCases = {
		{1,2},
		{2,3}
	};

	for (auto& [a, b] : testCases) {
		cout << getSum(a, b) << endl;
	}

	return 0;
}