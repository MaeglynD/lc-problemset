#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s){
  int lmin = 0, lmax = 0;

  for (char& c : s){
    if (c == '('){
      lmin++;
      lmax++;
    } else if (c == ')'){
      lmin = max(0, lmin-1);
      lmax--;

      if (lmax < 0)
        return false;
    } else {
      lmin = max(0, lmin-1);
      lmax++;
    }
  }

  return !lmin && lmax > -1;
}

int main(){
  vector<string> testCases = {
    "()",
    "(*)",
    "(*))",
    "()(()*)))",
    "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"
  };

  for (auto& test : testCases)
    cout << checkValidString(test) << endl;

  return 0;
}