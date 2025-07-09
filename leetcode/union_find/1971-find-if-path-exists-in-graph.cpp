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

class Solution {
    public:
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            vector<int> id(n);
            vector<int> size(n,1);
            for(int i =0; i<n; ++i) id[i] = i;
            auto find = [&](int x) {
                while(x != id[x]){
                    id[x] = id[id[x]];
                    x = id[x];
                }
                return x;
            };
            auto union_set = [&](int x, int y) {
                auto rootX = find(x);
                auto rootY = find(y);
                if(rootX == rootY)
                    return ;
                if(size[rootX] <= size[rootY]) {
                    id[rootX] = rootY;
                    size[rootY] += size[rootX];
                }else {
                    id[rootY] = rootX;
                    size[rootX] += size[rootY];
                }
            };
            for(auto&e : edges) {
                union_set(e[0], e[1]);
            }
            return find(source) == find(destination);
        }
};

int main() {
    Solution so;
    vector<vector<int>> edges;
    int n, source, destination;
    {

        edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
        int n = 6, source = 0, destination = 5;
        auto res = so.validPath(n, edges, source, destination);
        cout << (res ? "true" : "false") << endl; // Output: true
    }
    {

        edges = {{0,1},{1,2},{2,3},{3,4},{4,5}};
        n = 6, source = 0, destination = 6;
        auto res = so.validPath(n, edges, source, destination);
        cout << (res ? "true" : "false") << endl; // Output: false
    }
    {

        edges = {{0,1},{1,2},{2,3},{3,4},{4,5},{5,6}};
        n = 7, source = 0, destination = 6;
        auto res = so.validPath(n, edges, source, destination);
        cout << (res ? "true" : "false") << endl; // Output:
    }
    return 0;
}