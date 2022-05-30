#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target){
  int m = matrix.size(), n = matrix[0].size();
  int l = 0, r = (m*n)-1; 

  while (l <= r){
    int mid = l+(r-l)/2, num = matrix[mid/n][mid%n];

    if (num == target){
      return true;
    } else if (num > target){
      r = mid-1;
    } else {
      l = mid+1;
    }
  }

  return false; 
}

int main(){
  vector<pair<vector<vector<int>>, int>> testCases = {
    {{{1,3,5,7}, {10,11,16,20},{23,30,34,60}}, 3},
    {{{1,3,5,7}, {10,11,16,20},{23,30,34,60}}, 13}
  };

  for (auto& [matrix, target] : testCases)
    cout << searchMatrix(matrix, target) << endl;

  return 0;
}