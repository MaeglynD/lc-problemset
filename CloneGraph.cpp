#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node {
  public:
    int val;
    vector<Node*> neighbors;

    Node() {
      val = 0;
      neighbors = vector<Node*>();
    }
    Node(int _val) {
      val = _val;
      neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
      val = _val;
      neighbors = _neighbors;
    }
};

Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
  if (visited.count(node)) {
    return visited[node];
  }

  Node* clone = new Node(node->val);

  visited[node] = clone;

  for (auto n : node->neighbors) {
    clone->neighbors.push_back(dfs(n, visited));
  }

  return clone;
}

Node* cloneGraph(Node* node) {
  unordered_map<Node*, Node*> visited;

  visited[nullptr] = nullptr;

  return dfs(node, visited);
}

int main () {
  // 
	return 0;
}
