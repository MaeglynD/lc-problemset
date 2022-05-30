#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h){
  int l = 1, r = *max_element(piles.begin(), piles.end());

  if (h == piles.size())
    return r;

  while (l <= r){
    int mid = l+(r-l)/2, htmp = h;

    for (int& n : piles){
      htmp-=ceil(1.0*n/mid);

      if (htmp < 0)
        break;
    }

    if (htmp >= 0){
      r = mid-1;
    } else {
      l = mid+1;
    }
  }

  return l; 
}

int main(){
  vector<pair<vector<int>, int>> testCases = {
    {{3,6,7,11}, 8},
    {{30,11,23,4,20}, 5},
    {{30,11,23,4,20}, 6},
  };

  for (auto& [piles, h] : testCases)
    cout << minEatingSpeed(piles, h) << endl;

  return 0;
}