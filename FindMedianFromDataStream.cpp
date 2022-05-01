#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Priority queues
class MedianFinder {
  public: 
    priority_queue<int> lheap;
    priority_queue<int, vector<int>, greater<int>> rheap;

    void addNum(int num){
      if (lheap.empty() || num <= lheap.top()) {
        lheap.push(num);
      } else {
        rheap.push(num);
      }

      if (abs((int)(lheap.size()-rheap.size())) > 1) {
        if (lheap.size() > rheap.size()) {
          rheap.push(lheap.top());
          lheap.pop();
        } else {
          lheap.push(rheap.top());
          rheap.pop();
        }
      }
    }

    double findMedian(){
      if (lheap.size() == rheap.size()) {
        return (lheap.top()+rheap.top())/2.0;
      }

      return lheap.size() > rheap.size() ? lheap.top() : rheap.top();
    }
};


// Multiset
class MedianFinderAlt {
  public:
    multiset<int> nums = {INT_MIN};
    multiset<int>::iterator mid = nums.begin();

    void addNum(int num) {
      nums.insert(num);

      if (nums.size() % 2 == 0) {
        if (num >= *mid) {
          mid++;
        }
      } else {
        if (num < *mid) {
          mid--;
        }
      }
    }

    double findMedian() {
      if (nums.size() % 2 == 0) {
        return *mid;
      } 

      double num = *mid;

      mid++;
      num += *mid;
      mid--;
      
      return num/2;
    }
};

int main () {
  vector<vector<int>> testCases = {
    {1, 2, 3},
    {123, 3, 12, 3, 4, 1, 1, 1, 4, 2, 923},
    {40,12,16,14,35,19,34,35,28}
  };

  for (auto& test : testCases) {
    MedianFinder medianFinder; 

    for (int& n : test) {
      medianFinder.addNum(n);

      cout << "median: " << medianFinder.findMedian() << endl;
    }

    cout << "----" << endl;
  }

  return 0;
}