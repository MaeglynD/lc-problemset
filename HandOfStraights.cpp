#include <bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
  if (hand.size() % groupSize != 0)
    return false;
  
  map<int, int> hm;

  for (int& h : hand)
    hm[h]++;
  
  auto it = hm.begin();

  while (it != hm.end()){
    if (it->second > 0){
      for (int i = 0; i < groupSize; ++i){
        if (hm[it->first+i]){
          hm[it->first+i]--;
        } else {
          return false;
        }
      }
    } else {
      it++;
    }
  }

  return true;
}

int main(){
  vector<pair<vector<int>, int>> testCases = {
    {{1,2,3,6,2,3,4,7,8}, 3},
    {{1,2,3,4,5}, 4}
  };

  for (auto& [hand, groupSize] : testCases){
    cout << isNStraightHand(hand, groupSize) << endl;
  }

  return 0;
}

