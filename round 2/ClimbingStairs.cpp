#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int climbStairs(int n) {
  int a = 1, b = 1;

  for (int i = 1; i < n; ++i) {
    int tmp = b;

    b = a+b;
    a = tmp;
  }

  return b;
}

int main () {
  vector<int> testCases = {
    2, 3, 4
  };

  for (auto& test : testCases) {
    cout << climbStairs(test) << endl;
  }

  return 0;
}