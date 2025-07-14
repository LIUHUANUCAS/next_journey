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
    // 滑动窗口模板
    // 1. 窗口的定义
    // 2. 窗口的移动
    // 3. 窗口的更新

    void slidingWindowTemplate(vector<int> A) {
        int left = 0, right = 0;
        while (right < s.size()) {
            // 扩大窗口
            char c = s[right];
            right++;

            // 如果不满足条件，缩小窗口
            while (窗口不满足条件) {
                char d = s[left];
                left++;
            }

            // 此时窗口 [left, right) 满足条件，进行结果更新
        }
    };
    int main() {
        Solution so;

        return 0;
    }