#include <bits/stdc++.h>
using namespace std;

bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target){
  bool a = false, b = false, c = false;
  
  for (vector<int>& t : triplets){
    if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]){
      a |= t[0] == target[0];
      b |= t[1] == target[1];
      c |= t[2] == target[2];
    }

    if (a && b && c)
      return true;
  }

  return false;
}

int main(){
  vector<pair<vector<vector<int>>, vector<int>>> testCases = {
    {{{2,5,3},{1,8,4},{1,7,5}}, {2,7,5}},
    {{{3,4,5},{4,5,6}}, {3,2,5}}
  };
  
  for (auto& [triplets, target] : testCases){
    cout << mergeTriplets(triplets, target) << endl;
  }

  return 0;
}
