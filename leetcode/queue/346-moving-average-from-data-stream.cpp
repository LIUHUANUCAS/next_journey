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
class MovingAverage {
    queue<int> que;
    int n;
    double sum;

   public:
    MovingAverage(int size) {
        n = size;
        sum = 0;
    }

    double next(int val) {
        que.push(val);
        sum += val;
        if (que.size() > n) {
            auto x = que.front();
            sum -= x;
            que.pop();
        }
        return sum / que.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
int main() {
    int size;
    vector<int> A;
    {
        size = 3;
        MovingAverage* movingAverage = new MovingAverage(size);
        A = {1, 10, 3, 5};
        for (auto x : A) {
            auto r = movingAverage->next(x);  // 返回 1.0 = 1 / 1
            cout << "avg:" << r << endl;
        }
    }
    return 0;
}