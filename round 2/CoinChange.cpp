#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int coinChange(vector<int>& coins, int amount){
  if (!amount) 
    return 0;

  int mem[amount+1];

  fill(mem, mem+amount+1, -1);
  sort(coins.begin(), coins.end());

  mem[0] = 0;

  for (int i = 1; i <= amount; ++i) {
    int freq = INT_MAX;

    for (int& c : coins) {
      if (c > i)
        break;

      if (mem[i-c] != -1)
        freq = min(freq, 1+mem[i-c]);
    }

    mem[i] = freq == INT_MAX ? -1 : freq;
  }

  return mem[amount];
}

int main () {
  vector<pair<vector<int>, int>> testCases = {
    {{1,2,5},11},
    {{2},3},
    {{1}, 0}
  };

  for (auto& [coins, amount] : testCases) {
    cout << coinChange(coins, amount) << endl;
  }

  return 0;
}