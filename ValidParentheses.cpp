#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isValid(string s) {
  stack<char> st;
  unordered_map<char, char> pairings = {
    {'{', '}'},
    {'[', ']'},
    {'(', ')'},
  };

  for (char& c : s) {
    if (pairings.count(c)) {
      st.push(pairings[c]);
    } else {
      if (st.empty() || st.top() != c) {
        return false;
      }
      
      st.pop();
    }
  }

  return st.empty();
}

int main () {
  vector<string> testCases = {
    "()",
    "()[]{}",
    "(]",
    "["
  };

  for (auto& test : testCases) {
    cout << isValid(test) << endl;
  }

  return 0;
}