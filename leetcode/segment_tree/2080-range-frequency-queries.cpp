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
struct kv {
    int value;
    int count;
};
class RangeFreqQuery {
    vector<unordered_map<int, int>> tree;
    int n;
    void build(vector<int>& A, int node, int l, int r) {
        if (r == l) {
            tree[node][A[l]]++;
        } else {
            int mid = (l + r) / 2;
            build(A, 2 * node + 1, l, mid);
            build(A, 2 * node + 2, mid + 1, r);
            tree[node] = merge(tree[node * 2 + 1], tree[node * 2 + 2]);
        }
    }
    int query(int key, int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return 0;
        if (ql <= l && qr >= r) {
            if (tree[node].find(key) != tree[node].end())
                return tree[node][key];
            return 0;
        }
        int mid = (l + r) / 2;
        return query(key, 2 * node + 1, l, mid, ql, qr) +
               query(key, 2 * node + 2, mid + 1, r, ql, qr);
    }
    unordered_map<int, int> merge(unordered_map<int, int>& m1,
                                  unordered_map<int, int>& m2) {
        unordered_map<int, int> res(m1.begin(), m1.end());
        for (auto& p : m2) {
            res[p.first] += p.second;
        }
        return res;
    }

   public:
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, {});
        build(arr, 0, 0, n - 1);
    }

    int query(int left, int right, int value) {
        return this->query(value, 0, 0, n - 1, left, right);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
int main() {
    vector<int> A;
    {
        A = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
        RangeFreqQuery* obj = new RangeFreqQuery(A);
        int left = 0, right = 11, value = 12;
        auto r = obj->query(left, right, value);
        cout << r << endl;
    }
    return 0;
}