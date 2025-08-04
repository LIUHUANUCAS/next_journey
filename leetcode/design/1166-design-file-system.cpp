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
class FileSystem {
    struct TrieNode {
        int val;
        string name;
        unordered_map<string, TrieNode*> next;
        TrieNode() : val(-1) {}
        TrieNode(int val) : val(val) {}
    };
    TrieNode* root;
    bool add(vector<string>& path, int val) {
        auto n = root;
        auto name = path.back();
        for (auto it = path.begin(); it + 1 != path.end(); ++it) {
            if (n->next.find(*it) == n->next.end())
                return false;
            n = n->next[*it];
        }
        if (n->next.find(name) != n->next.end())
            return false;
        n->next[name] = new TrieNode(val);
        return true;
    }
    int find(vector<string>& path) {
        auto n = root;
        for (auto& p : path) {
            if (n->next.find(p) == n->next.end())
                return -1;
            n = n->next[p];
        }
        return n->val;
    }
    vector<string> get_path(string& path) {
        vector<string> ret;
        if (path.empty())
            return ret;

        int n = path.size();
        for (auto i = path.begin(); i != path.end();) {
            auto j = i;
            while (j != path.end() && *j != '/') {
                ++j;
            }
            auto start = j;
            while (++j != path.end() && isalpha(*j))
                ;
            string str(start + 1, j);
            if (!str.empty())
                ret.push_back(str);
            i = j;
        }
        return ret;
    }

   public:
    FileSystem() { root = new TrieNode(-1); }

    bool createPath(string path, int value) {
        vector<string> path_list = get_path(path);
        if (path_list.empty())
            return false;
        return add(path_list, value);
    }

    int get(string path) {
        vector<string> path_list = get_path(path);
        if (path_list.empty())
            return -1;
        return find(path_list);
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
int main() {
    FileSystem fs;
    {
        string path = "/a/b/c";
        int value = 1;
        bool ret = fs.createPath(path, value);
        cout << "createPath(" << path << ", " << value << ") = " << ret
             << endl;  // true
    }
    {
        string path = "/a/b/c/d";
        int value = 2;
        bool ret = fs.createPath(path, value);
        cout << "createPath(" << path << ", " << value << ") = " << ret
             << endl;  // false
    }
    {
        string path = "/a/b/c";
        int ret = fs.get(path);
        cout << "get(" << path << ") = " << ret << endl;  // 1
    }
    {
        string path = "/a/b/c/d";
        int ret = fs.get(path);
        cout << "get(" << path << ") = " << ret << endl;  // -1
    }
    return 0;
}