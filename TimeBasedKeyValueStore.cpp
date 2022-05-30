#include <bits/stdc++.h>
using namespace std;

class TimeMap {
  public:
    unordered_map<string, vector<pair<int, string>>> hm;
    
    static bool comp(const pair<int, string>& a, const int n){
      return a.first <= n;
    }
    
    void set(string key, string value, int timestamp){
      hm[key].push_back({ timestamp, value });
    }

    string get(string key, int timestamp){
      auto& data = hm[key];

      if (!data.size() || data[0].first > timestamp)
        return "";
      
      auto it = lower_bound(data.begin(), data.end(), timestamp, comp);

      if (it == data.end() || it->first != timestamp)
        return prev(it)->second;

      return it->second;
    }
};

// initial solution
class TimeMapAlt {
  public:
    unordered_map<string, map<int, string>> hm;

    void set(string key, string value, int timestamp){
      hm[key][timestamp] = value;
    }

    string get(string key, int timestamp){
      auto& hmk = hm[key];

      if (!hmk.size() || hmk.begin()->first > timestamp)
        return "";

      auto it = hmk.lower_bound(timestamp);

      if (it == hmk.end() || it->first != timestamp)
        return prev(it)->second;

      return it->second;
    }
};

int main(){
  TimeMap timeMap;

  timeMap.set("foo", "bar", 1);  

  cout << timeMap.get("foo", 1) << endl;
  cout << timeMap.get("foo", 3) << endl;

  timeMap.set("foo", "bar2", 4);

  cout << timeMap.get("foo", 4) << endl;
  cout << timeMap.get("foo", 5) << endl;

//  map<string, map<int, string>> test;
//
//  test["something"][3] = "abc";
//
//  cout << test["something"][3] << endl;
  return 0;
}