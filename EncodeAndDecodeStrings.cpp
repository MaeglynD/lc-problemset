#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
  public:
    string encode(vector<string>& strs) {
      string ans = "";

      for (auto& s : strs) {
        ans += to_string(s.size()) + " " + s;
      }

      return ans;
    }
    
    vector<string> decode(string& str) {
      vector<string> ans;
      int i = 0;

      while(i < str.size()) {
        int delim = str.find_first_of(" ", i);
        int num = stoi(str.substr(i, delim-i));

        ans.push_back(str.substr(delim+1, num));
        i = delim + 1 + num;
      }

      return ans;
    }
};

int main () {
  Solution sol;
  vector<vector<string>> testCases = {
    {"lint","code","love","you"},
  };

  for (auto& test : testCases) {
    string encoded = sol.encode(test);
    vector<string> decoded = sol.decode(encoded);

    cout << "encoded: " << encoded << endl;
    cout << "decoded: [";

    for (auto& s : decoded) {
      cout << s << ", ";
    }

    cout << "]" << endl;
  }

  return 0;
}
