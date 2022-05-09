#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int numDecodings(string s){
  int mem[s.size()+1];
  
  mem[s.size()] = 1;

  for (int i = s.size()-1; i >= 0; --i) {
    if (s[i] == '0') {
      mem[i] = 0;
    } else {
      mem[i] = mem[i+1];

      if (i < s.size()-1 && (s[i] == '1' || (s[i] == '2' && s[i+1]-48 < 7)))
        mem[i]+=mem[i+2];
    } 
  }

  return mem[0];
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