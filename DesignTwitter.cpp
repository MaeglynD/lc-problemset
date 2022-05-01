#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Twitter {
  public:
    int time = 0;
    unordered_map<int, pair<unordered_set<int>, vector<pair<int, int>>>> users;

    void ensureUserIsCreated(int& userId) {
      if (!users.count(userId)) {
        users[userId] = {{userId}, {}};
      }
    }

    void postTweet(int userId, int tweetId) {
      ensureUserIsCreated(userId);

      users[userId].second.push_back({ time, tweetId });
      time++;
    }

    vector<int> getNewsFeed(int userId) {
      priority_queue<pair<int, int>> pq;
      vector<int> newsFeed;
      int i = 0;

      for (const int& id : users[userId].first) {
        for (auto& tweet : users[id].second) {
          pq.push(tweet);
        }
      }

      while(!pq.empty() && i < 10) {
        newsFeed.push_back(pq.top().second);
        pq.pop();
        i++;
      }

      return newsFeed;
    }

    void follow(int followerId, int followeeId) {
      ensureUserIsCreated(followerId);
      ensureUserIsCreated(followeeId);

      users[followerId].first.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
      ensureUserIsCreated(followerId);
      ensureUserIsCreated(followeeId);

      users[followerId].first.erase(followeeId);
    }
};

int main () {
  vector<pair<vector<string>, vector<vector<int>>>> testCases = {
    { 
      {"postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"},
      {{1, 5}, {1}, {1,2}, {2,6}, {1}, {1,2}, {1}}
    }
  };

  for (auto& [commands, commandData]: testCases) {
    Twitter twitter;

    for (int i = 0; i < commands.size(); ++i) {
      auto& command = commands[i];
      auto& data = commandData[i];

      cout << command << ", result: ";

      if (command == "getNewsFeed") {
        auto res = twitter.getNewsFeed(data[0]);

        for (int& x : res) {
          cout << x << ", ";
        }
      } else if (command == "postTweet") {
        twitter.postTweet(data[0], data[1]);
      } else if (command == "follow") {
        twitter.follow(data[0], data[1]);
      } else if (command == "unfollow") {
        twitter.unfollow(data[0], data[1]);
      }
      
      cout << endl;
    }
  }
  
  return 0;
}