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
    double findMaxAverage(vector<int>& A, int k) {
        int n = A.size();
        int i = 0, j = 0;
        double max_sum = -1e4, sum = 0;
        while (j < n) {
            int t = A[j];
            sum += t;
            j++;
            if (j - i < k) {
                continue;
            } else {
                max_sum = max(max_sum, sum / k);
                sum -= A[i];
                i++;
            }
        }
        return max_sum;
    }
};
int main() {
    Solution so;

    return 0;
}