#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums){
  unordered_set<int> mem;

  for (int& n : nums){
    if (mem.count(n))
      return true;

    mem.insert(n);
  }

  return false;
}

int main(){
  vector<vector<int>> testCases = {
    {1,2,3,1},
    {1,2,3}
  };

  for (auto& test : testCases){
    cout << containsDuplicate(test) << endl;
  }

  return 0;
}
