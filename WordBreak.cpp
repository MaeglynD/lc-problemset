#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool wordBreak(string s, vector<string> wordDict) {
	bool mem[s.size()+1];

	mem[s.size()] = true;

	for (int i = s.size()-1; i >= 0; --i) {
		mem[i] = false;

		for (int j = 0; j < wordDict.size(); ++j) {
			if (i + wordDict[j].size() <= s.size() && wordDict[j] == s.substr(i, wordDict[j].size()))	{
				mem[i] = mem[i + wordDict[j].size()];
			}

			if (mem[i]) {
				break;
			}
		}
	}

	return mem[0];
}

int main () {
	vector<pair<string, vector<string>>> testCases = {
		{ "leetcode", { "leet","code" } },
		{ "applepenapple", { "apple","pen" }},
		{ "catsandog", { "cats","dog","sand","and","cat" }},
	};

	for (auto& [s, wordDict] : testCases) {
		cout << wordBreak(s, wordDict) << endl;
	}

	return 0;
}
