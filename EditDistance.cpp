#include <bits/stdc++.h>
using namespace std;

int minDistance(string a, string b){
  int as = a.size(), bs = b.size();
  int mem[as+1][bs+1];

  mem[0][0] = 0;
  mem[as][bs] = 0;

  for (int i = 0; i < as; ++i)
    mem[i][bs] = as-i;
  for (int i = 0; i < bs; ++i)
    mem[as][i] = bs-i;

  for (int i = as-1; i >= 0; --i)
    for (int j = bs-1; j >= 0; --j)
      mem[i][j] = a[i] == b[j]
        ? mem[i+1][j+1]
        : min(min(mem[i][j+1], mem[i+1][j]), mem[i+1][j+1])+1;

  return mem[0][0];
}

int main(){
  vector<pair<string, string>> testCases = {
    {"mart", "karma"},
    {"horse", "ros"},
    {"intention", "execution"},
    {"a", "a"},
    {"", ""},
    {"a", "b"}
  };

  for (auto& [a, b] : testCases){
    cout << minDistance(a, b) << endl;
  }

  return 0;
}
