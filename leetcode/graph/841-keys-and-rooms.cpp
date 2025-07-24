#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../header/data_type.h"

using namespace std;
class Solution {
    unordered_map<int, int> visited;

   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited.clear();
        int n = rooms.size();
        dfs(rooms, 0);
        return visited.size() == n;
    }
    void dfs(vector<vector<int>>& rooms, int i) {
        visited[i]++;
        for (auto& adj : rooms[i]) {
            if (!visited.count(adj)) {
                dfs(rooms, adj);
            }
        }
    }
};

int main() {
    Solution so;

    return 0;
}