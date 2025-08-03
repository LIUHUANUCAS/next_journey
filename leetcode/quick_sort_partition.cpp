

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

using namespace std;
int partition(vector<int>& A, int low, int high) {
    int p = A[low];
    int first = low, last = high;
    auto f = [&](int x) { return x < p; };

    while (1) {
        while (1) {
            if (first == last)
                return first;
            else if (f(A[first]))
                ++first;
            else
                break;
        }
        --last;
        while (1) {
            if (first == last)
                return first;
            else if (!f(A[last]))
                --last;
            else
                break;
        }
        swap(A[first], A[last]);
        ++first;
    }
}
int partition2(vector<int>& A, int low, int high) {
    int first = low, last = high;
    int p = A[low];
    while (1) {
        while (A[first] < p)
            ++first;
        while (p < A[last])
            --last;
        if (first >= last)
            return first;
        swap(A[first], A[last]);
        ++first;
    }
}

int main() {
    vector<int> A = {3, 2, 1, 5, 4};
    int n = A.size();
    cout << "Before partition: ";
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
    int idx = partition(A, 0, n);
    cout << "After partition: ";
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
    cout << "Partition index: " << idx << endl;
}
