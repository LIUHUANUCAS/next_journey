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

class ZigzagIterator {
    using VecIntIter = std::vector<int>::iterator;
    pair<VecIntIter, VecIntIter> it1, it2;
    queue<pair<VecIntIter, VecIntIter>> que;

   public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        it1 = {v1.begin(), v1.end()};
        it2 = {v2.begin(), v2.end()};
        if (it1.first != it1.second)
            que.push(it1);
        if (it2.first != it2.second)
            que.push(it2);
    }

    int next() {
        auto it = que.front();
        que.pop();
        int val = *it.first;
        it.first = it.first + 1;
        if (it.first != it.second) {
            que.push(it);
        }
        return val;
    }

    bool hasNext() { return !que.empty(); }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    Solution so;

    return 0;
}