#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
  int l = 0, r = s.size()-1;

  while (l < r){
    if (!isalnum(s[l])){
      l++;
    } else if (!isalnum(s[r])){
      r--;
    } else {
      if (tolower(s[l]) != tolower(s[r]))
        return false;

      l++;
      r--;
    }
  }

  return true;
}

int main(){
  vector<string> testCases = {
    "A man, a plan, a canal: Panama",
    "race a car",
    "0P"
  };

  for (auto& test : testCases)
    cout << isPalindrome(test) << endl;

  return 0;
}
