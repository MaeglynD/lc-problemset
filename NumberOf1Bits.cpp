#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int hammingWeight(uint32_t n) {
	int total = 0;

	while (n != 0) {
		n &= (n -1);
		total++;
	}

	return total;
}

int main () {
	vector<int> testCases = {1, 2, 3, 4, 192, 30};

	for (auto test : testCases) {
		cout << hammingWeight(test) << endl;
	}

	return 0;
}