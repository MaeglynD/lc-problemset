#include <bits/stdc++.h>
using namespace std;

bool dfs(unordered_map<string, int>& c2i, unordered_map<int, string>& i2c, unordered_map<int, vector<int>>& ticketMap, vector<string>& ans, int& ts, int depth, int index){
  ans[depth] = i2c[index];

  if (depth == ts-1)
    return true;

  for (int& n : ticketMap[index]){
    if (n == -1)
      continue;

    int tmp = n;

    n = -1;

    if (dfs(c2i, i2c, ticketMap, ans, ts, depth+1, tmp))
      return true;

    n = tmp;
  }
  
  return false;
}

vector<string> findItinerary(vector<vector<string>>& tickets){
  int ts = tickets.size()+1;
  set<string> codes;
  vector<string> ans(ts);
  unordered_map<string, int> c2i;
  unordered_map<int, string> i2c;
  unordered_map<int, vector<int>> ticketMap;

  ans[0] = "JFK";

  for (auto& t : tickets)
    codes.insert(t.begin(), t.end());
 
  for (auto [it, i] = tuple{codes.begin(), 0}; it != codes.end(); it++, i++){
    c2i[*it] = i;
    i2c[i] = *it;
  }

  for (auto& t : tickets)
    ticketMap[c2i[t[0]]].push_back(c2i[t[1]]);

  for (auto& [k, v] : ticketMap)
    sort(v.begin(), v.end());
    
  dfs(c2i, i2c, ticketMap, ans, ts, 0, c2i["JFK"]);

  return ans;
}

int main(){
  vector<vector<vector<string>>> testCases = {
    {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}},
    {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}}
  };

  for (auto& test : testCases){
    auto res = findItinerary(test);

    for (auto& x : res)
      cout << x << ", "; 

    cout << endl;
  }

  return 0;
}
