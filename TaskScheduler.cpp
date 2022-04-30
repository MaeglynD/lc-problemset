#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int leastInterval(vector<char>& tasks, int n) {
  int time = 0;
  int alph[26] = {0};
  priority_queue<int> heap; 
  queue<pair<int, int>> q;

  for (char& c : tasks) {
    alph[c-'A']++;
  }

  for (int& n : alph) {
    if (n) {
      heap.push(n);
    }
  }

  while(!heap.empty() || !q.empty()) {
    if (!q.empty() && q.front().first == time) {
      heap.push(q.front().second);
      q.pop();
    }

    if (!heap.empty()) {
      int top = heap.top();

      if (top != 1) {
        top--;
        q.push({ time+1+n, top });
      }

      heap.pop();
    }

    time++;
  }

  return time;
}

int main () {
  vector<pair<vector<char>, int>> testCases = {
    {{'A','A','A','B','B','B'}, 2},
    {{'A','A','A','B','B','B'}, 0},
    {{'A','A','A','A','A','A','B','C','D','E','F','G'}, 2}
  };

  for (auto& [tasks, n] : testCases) {
    cout << leastInterval(tasks, n) << endl;
  }

  return 0;
}