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
   public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        vector<int> ret;
        deque<int> dq;
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            while (!dq.empty() && A[dq.back()] < A[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i - dq.front() >= k) {
                dq.pop_front();
            }
            if (i >= k - 1) {
                ret.push_back(A[dq.front()]);
            }
        }
        return ret;
    }
    vector<int> maxSlidingWindow2(vector<int>& A, int k) {
        int n = A.size();
        vector<int> ret;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; ++i) {
            pq.push({A[i], i});
        }
        ret.push_back(pq.top().first);
        for (int i = k; i < n; ++i) {
            pq.push({A[i], i});
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }
            ret.push_back(pq.top().first);
        }
        return ret;
    }
};

int main() {
    Solution so;

    return 0;
}