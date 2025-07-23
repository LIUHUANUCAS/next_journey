#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../header/data_type.h"

using namespace std;
/*
// Definition for a Node.
*/
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

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        // return bfs(node);
        unordered_map<Node*, Node*> visited;
        return dfs(node, visited);
    }
    Node* bfs(Node* node) {
        if (node == nullptr)
            return node;
        queue<Node*> que;
        que.push(node);
        unordered_map<Node*, Node*> visited;
        visited[node] = new Node(node->val);
        while (!que.empty()) {
            auto x = que.front();
            que.pop();
            auto copy_node = visited[x];
            for (auto adj : x->neighbors) {
                if (!visited.count(adj)) {
                    visited[adj] = new Node(adj->val);
                    que.push(adj);
                }
                copy_node->neighbors.push_back(visited[adj]);
            }
        }
        return visited[node];
    }
    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        if (node == nullptr)
            return node;
        auto it = visited.find(node);
        if (it != visited.end()) {
            return it->second;
        }
        Node* copy_node = new Node(node->val);
        visited[node] = copy_node;
        for (auto& adj : node->neighbors) {
            auto copy_adj = dfs(adj, visited);
            copy_node->neighbors.push_back(copy_adj);
        }
        return copy_node;
    }
};
int main() {
    Solution so;

    return 0;
}