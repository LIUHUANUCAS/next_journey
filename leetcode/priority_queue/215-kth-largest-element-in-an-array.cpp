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
    int findKthLargest(vector<int>& A, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        for (auto e : A) {
            que.push(e);
            if (que.size() > k) {
                que.pop();
            }
        }
        return que.top();
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {3, 2, 1, 5, 6, 4};
        int k = 2;
        cout << so.findKthLargest(A, k) << endl;  // 5
    }

    {
        A = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        int k = 4;
        cout << so.findKthLargest(A, k) << endl;  // 4
    }
    return 0;
}