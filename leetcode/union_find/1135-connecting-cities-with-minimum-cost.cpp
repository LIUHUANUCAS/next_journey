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
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<int> id(n + 1);
        vector<int> size(n + 1, 1);
        int count = n;
        for (int i = 0; i <= n; ++i) {
            id[i] = i;
        }

        auto find = [&](int x) {
            while (x != id[x]) {
                // id[x] = id[id[x]];
                x = id[x];
            }
            return x;
        };
        auto union_set = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY)
                return false;
            if (size[rootX] < size[rootY]) {
                id[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                id[rootY] = rootX;
                size[rootX] += size[rootY];
            }
            count--;
            // printf("union %d %d, %d,%d, size:%d\n", x, y, rootX, rootY,
            // count); printvector(size);
            return true;
        };
        sort(connections.begin(), connections.end(),
             [](vector<int>& a, vector<int>& b) { return a[2] < b[2]; });
        // printvector(connections);
        int cost = 0;
        for (auto& e : connections) {
            if (union_set(e[0], e[1])) {
                cost += e[2];
                if (count == 1) {
                    return cost;
                }
            }
        }
        if (count == 1)
            return cost;
        return -1;
    }
};

int main() {
    Solution so;
    vector<vector<int>> connections;
    // {
    //     connections = {{1, 2, 3}, {2, 3, 4}, {1, 3, 5}, {1, 4, 6}, {2, 4,
    //     7}}; cout << so.minimumCost(4, connections) << endl;  // 12
    // }
    // {
    //     connections = {{1, 2, 5}, {1, 3, 6}, {2, 3, 1}};
    //     cout << so.minimumCost(3, connections) << endl;  // 6
    // }
    {
        connections = {
            {2, 1, 22135},   {3, 1, 13746},   {4, 3, 37060},   {5, 2, 48513},
            {6, 3, 49607},   {7, 1, 97197},   {8, 2, 95909},   {9, 2, 82668},
            {10, 2, 48372},  {11, 4, 17775},  {12, 2, 6017},   {13, 1, 51409},
            {14, 2, 12884},  {15, 7, 98902},  {16, 14, 52361}, {17, 8, 11588},
            {18, 12, 86814}, {19, 17, 49581}, {20, 4, 41808},  {21, 11, 77039},
            {22, 10, 80279}, {23, 16, 61659}, {24, 12, 89390}, {25, 24, 10042},
            {26, 12, 78278}, {27, 15, 30756}, {28, 6, 2883},   {29, 8, 3478},
            {30, 7, 29321},  {31, 12, 47542}, {32, 20, 35806}, {33, 3, 26531},
            {34, 12, 16321}, {35, 27, 82484}, {36, 7, 55920},  {37, 24, 21253},
            {38, 23, 90537}, {39, 7, 83795},  {40, 36, 70353}, {41, 34, 76983},
            {42, 14, 63416}, {43, 15, 39590}, {44, 9, 86794},  {45, 3, 31968},
            {46, 19, 32695}, {47, 17, 40287}, {48, 1, 27993},  {49, 12, 86349},
            {50, 11, 52080}, {17, 27, 65829}, {42, 45, 87517}, {14, 23, 96130},
            {5, 50, 3601},   {10, 17, 2017},  {26, 44, 4118},  {26, 29, 93146},
            {1, 9, 56934},   {22, 43, 5984},  {3, 22, 13404},  {13, 28, 66475},
            {11, 14, 93296}, {16, 44, 71637}, {7, 37, 88398},  {7, 29, 56056},
            {2, 34, 79170},  {40, 44, 55496}, {35, 46, 14494}, {32, 34, 25143},
            {28, 36, 59961}, {10, 49, 58317}, {8, 38, 33783},  {8, 28, 19762},
            {34, 41, 69590}, {27, 37, 26831}, {15, 23, 53060}, {5, 11, 7570},
            {20, 42, 98814}, {18, 34, 96014}, {13, 43, 94702}, {1, 46, 18873},
            {44, 45, 43666}, {22, 40, 69729}, {4, 25, 28548},  {8, 46, 19305},
            {15, 22, 39749}, {33, 48, 43826}, {14, 15, 38867}, {13, 22, 56073},
            {3, 46, 51377},  {13, 15, 73530}, {6, 36, 67511},  {27, 38, 76774},
            {6, 21, 21673},  {28, 49, 72219}, {40, 50, 9568},  {31, 37, 66173},
            {14, 29, 93641}, {4, 40, 87301},  {18, 46, 41318}, {2, 8, 25717},
            {1, 7, 3006},    {9, 22, 85003},  {14, 45, 33961}, {18, 28, 56248},
            {1, 31, 10007},  {3, 24, 23971},  {6, 28, 24448},  {35, 39, 87474},
            {10, 50, 3371},  {7, 18, 26351},  {19, 41, 86238}, {3, 8, 73207},
            {11, 34, 75438}, {3, 47, 35394},  {27, 32, 69991}, {6, 40, 87955},
            {2, 18, 85693},  {5, 37, 50456},  {8, 20, 59182},  {16, 38, 58363},
            {9, 39, 58494},  {39, 43, 73017}, {10, 15, 88526}, {16, 23, 48361},
            {4, 28, 59995},  {2, 3, 66426},   {6, 17, 29387},  {15, 38, 80738},
            {12, 43, 63014}, {9, 11, 90635},  {12, 20, 36051}, {13, 25, 1515},
            {32, 40, 72665}, {10, 40, 85644}, {13, 40, 70642}, {12, 24, 88771},
            {14, 46, 79583}, {30, 49, 45432}, {21, 34, 95097}, {25, 48, 96934},
            {2, 35, 79611},  {9, 26, 71147},  {11, 37, 57109}, {35, 36, 67266},
            {42, 43, 15913}, {3, 30, 44704},  {4, 32, 46266},  {5, 10, 94508},
            {31, 39, 45742}, {12, 25, 56618}, {10, 45, 79396}, {15, 28, 78005},
            {19, 32, 94010}, {36, 46, 4417},  {6, 35, 7762},   {10, 13, 12161},
            {49, 50, 60013}, {20, 23, 6891},  {9, 50, 63893},  {35, 43, 74832},
            {10, 24, 3562},  {6, 8, 47831},   {29, 32, 82689}, {7, 47, 71961},
            {14, 41, 82402}, {20, 33, 38732}, {16, 26, 24131}, {17, 34, 96267},
            {21, 46, 81067}, {19, 47, 41426}, {13, 24, 68768}, {1, 25, 78243},
            {2, 27, 77645},  {11, 25, 96335}, {31, 45, 30726}, {43, 44, 34801},
            {3, 42, 22953},  {12, 23, 34898}, {37, 43, 32324}, {18, 44, 18539},
            {8, 13, 59737},  {28, 37, 67994}, {13, 14, 25013}, {22, 41, 25671},
            {1, 6, 57657},   {8, 11, 83932},  {42, 48, 24122}, {4, 15, 851},
            {9, 29, 70508},  {7, 32, 53629},  {3, 4, 34945},   {2, 32, 64478},
            {7, 30, 75022},  {14, 19, 55721}, {20, 22, 84838}, {22, 25, 6103},
            {8, 49, 11497},  {11, 32, 22278}, {35, 44, 56616}, {12, 49, 18681},
            {18, 43, 56358}, {24, 43, 13360}, {24, 47, 59846}, {28, 43, 36311},
            {17, 25, 63309}, {1, 14, 30207},  {39, 48, 22241}, {13, 26, 94146},
            {4, 33, 62994},  {40, 48, 32450}, {8, 19, 8063},   {20, 29, 56772},
            {10, 27, 21224}, {24, 30, 40328}, {44, 46, 48426}, {22, 45, 39752},
            {6, 43, 96892},  {2, 30, 73566},  {26, 36, 43360}, {34, 36, 51956},
            {18, 20, 5710},  {7, 22, 72496},  {3, 39, 9207},   {15, 30, 39474},
            {11, 35, 82661}, {12, 50, 84860}, {14, 26, 25992}, {16, 39, 33166},
            {25, 41, 11721}, {19, 40, 68623}, {27, 28, 98119}, {19, 43, 3644},
            {8, 16, 84611},  {33, 42, 52972}, {29, 36, 60307}, {9, 36, 44224},
            {9, 48, 89857},  {25, 26, 21705}, {29, 33, 12562}, {5, 34, 32209},
            {9, 16, 26285},  {22, 37, 80956}, {18, 35, 51968}, {37, 49, 36399},
            {18, 42, 37774}, {1, 30, 24687},  {23, 43, 55470}, {6, 47, 69677},
            {21, 39, 6826},  {15, 24, 38561}};
        cout << so.minimumCost(50, connections) << endl;  // 1000000
    }
    return 0;
}