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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for (const auto& entry : freq_map) {
            pq.push({entry.second, entry.first});
        }
        vector<int> result;
        for (int i = 0; i < k && !pq.empty(); ++i) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

int main() {
    Solution so;
    vector<int> A;
    int k;
    {
        A = {1, 1, 1, 2, 2, 3};
        k = 2;
        vector<int> result = so.topKFrequent(A, k);
        cout << "Top " << k << " frequent elements: ";
        printvector(result);
    }
    {
        A = {1};
        k = 1;
        vector<int> result = so.topKFrequent(A, k);
        cout << "Top " << k << " frequent elements: ";
        printvector(result);
    }
    return 0;
}