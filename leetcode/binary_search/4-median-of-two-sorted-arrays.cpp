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
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        int i = 0, j = m - 1, l = 0, r = n - 1;
        int a = get_kth_element(A, i, j, B, l, r, (m + n + 1) / 2);
        int b = get_kth_element(A, i, j, B, l, r, (m + n + 2) / 2);
        return (a + b) * 0.5;
    }

    double get_kth_element(vector<int>& A,
                           int i,
                           int j,
                           vector<int>& B,
                           int l,
                           int r,
                           int kth) {
        int m = j - i + 1;
        int n = r - l + 1;
        if (m > n) {
            return get_kth_element(B, l, r, A, i, j, kth);
        }

        if (m == 0) {
            return B[l + kth - 1];
        }

        if (kth == 1) {
            return min(A[i], B[l]);
        }

        int x = i + min(m, kth / 2) - 1;
        int y = l + min(n, kth / 2) - 1;

        if (A[x] > B[y]) {
            return get_kth_element(A, i, j, B, y + 1, r, kth - (y - l + 1));
        } else {
            return get_kth_element(A, x + 1, j, B, l, r, kth - (x - i + 1));
        }
    }

    double findMedianSortedArrays1(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        int i = 0, j = m, l = 0, r = n;
        int len = m + n;
        while (len > 1) {
            int x = i + (j - i) / 2;
            int y = r + (r - l) / 2;

            // only B array
            if (i >= j) {
                if (len & 1) {
                    return B[y];
                } else {
                    return (B[y] + B[y - 1]) * 0.5;
                }
            }
            // only A array
            if (l >= r) {
                if (len & 1) {
                    return B[x];
                } else {
                    return (B[x] + B[x - 1]) * 0.5;
                }
            }

            if (A[x] == B[y]) {
                len -= (x - i + 1);
                len -= (r - y);
                i = x + 1;
                r = y;
            } else if (A[x] < B[y]) {
                len -= (x - i + 1);
                len -= (r - y);
                i = x + 1;
                r = y;
            } else if (A[x] > B[y]) {
                len -= (y - l + 1);
                len -= (j - x);
                l = y + 1;
                j = x;
            }
        }
        return -1;
    }
};
int main() {
    Solution so;

    return 0;
}