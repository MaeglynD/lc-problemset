#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int dfs(int i, string &s, int *mem) {
	if (mem[i] != -1) {
		return mem[i];
	}

	if (s[i] == '0') {
		return 0;
	}

	mem[i] = dfs(i+1, s, mem);
	
	if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] - '0' < 7)) {
		mem[i] += dfs(i+2, s, mem);
	}

	return mem[i];
}

int numDecodings(string s) {
	int mem[s.size()+1];

	fill(mem, mem + s.size(), -1);
	mem[s.size()] = 1;

	return dfs(0, s, mem);
}

int main () {
	vector<string> testCases = {
		"12",
		"226",
		"06"
	};

	for (auto& test : testCases) {
		cout << numDecodings(test) << endl;
	}

	return 0;
}
