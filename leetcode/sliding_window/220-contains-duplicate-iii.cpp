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
    bool containsNearbyAlmostDuplicate(vector<int>& A,
                                       int indexDiff,
                                       int valueDiff) {
        int n = A.size();
        map<int, int> m;  // {value,count} in window
        int j = 0, i = 0;
        while (j < n) {
            int c = A[j];
            int current_index_diff = j - i;
            j++;

            if (current_index_diff <= indexDiff) {
                // -valueDiff <= A[j] - A[i] <= valueDiff
                // A[i] <= A[j] + valueDiff && A[i] >= A[j] - valueDiff
                int left = c - valueDiff;
                int right = c + valueDiff;
                auto lower = m.lower_bound(left);
                // auto upper = m.upper_bound(right);

                if (lower != m.end() && lower->first <= right) {
                    return true;
                }

                m[c]++;
                if (current_index_diff >= indexDiff) {
                    int l = A[i];
                    int count = m[l];
                    if (--count == 0)
                        m.erase(l);
                    i++;
                }
            }
        }

        return false;
    }

    bool brute_force(vector<int>& A, int indexDiff, int valueDiff) {
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int x = abs(A[i] - A[j]);
                if (x <= valueDiff && abs(j - i) <= indexDiff)
                    return true;
            }
        }
        return false;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int indexDiff, valueDiff;
    {
        A = {1, 5, 9, 1, 5, 9};
        indexDiff = 2;
        valueDiff = 3;
        cout << so.containsNearbyAlmostDuplicate(A, indexDiff, valueDiff)
             << endl;  // false
    }
    {
        A = {1, 2, 3, 1};
        indexDiff = 3;
        valueDiff = 0;
        cout << so.containsNearbyAlmostDuplicate(A, indexDiff, valueDiff)
             << endl;  // true
    }
    {
        A = {1, 0, 1, 1};
        indexDiff = 1;
        valueDiff = 2;
        cout << so.containsNearbyAlmostDuplicate(A, indexDiff, valueDiff)
             << endl;  // true
    }

    {
        A = {1, 2, 3, 1};
        indexDiff = 3;
        valueDiff = 0;
        cout << so.containsNearbyAlmostDuplicate(A, indexDiff, valueDiff)
             << endl;  // true
    }
    {
        A = {1, 0, 1, 1};
        indexDiff = 1;
        valueDiff = 2;
        cout << so.containsNearbyAlmostDuplicate(A, indexDiff, valueDiff)
             << endl;  // true
    }
    return 0;
}