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
    struct Dir {
        unordered_map<string, Dir*> dirs;
        unordered_map<string, string> files;
    };
    Dir* root;
    vector<string> split(const string& str, char ch) {
        vector<string> res;
        int i = 0, n = str.size();
        while (i < n) {
            while (i < n && str[i] == ch)
                ++i;
            int j = i;
            while (i < n && str[i] != ch)
                ++i;
            if (i != j) {
                res.emplace_back(str.substr(j, i - j));
            }
        }
        return res;
    }

   public:
    FileSystem() { root = new Dir(); }

    vector<string> ls(string path) {
        Dir* r = root;
        vector<string> files;
        if (path != "/") {
            vector<string> d = split(path, '/');
            for (int i = 0; i + 1 < d.size(); ++i) {
                r = r->dirs[d[i]];
            }
            if (r->files.find(d.back()) != r->files.end()) {
                files.emplace_back(d.back());
                return files;
            } else {
                r = r->dirs[d.back()];
            }
        }
        for (auto& [key, _] : r->dirs) {
            files.emplace_back(key);
        }
        for (auto& [key, _] : r->files) {
            files.emplace_back(key);
        }
        sort(files.begin(), files.end());
        return files;
    }

    void mkdir(string path) {
        Dir* r = root;
        vector<string> path_dir = split(path, '/');
        for (auto& d : path_dir) {
            if (r->dirs.find(d) == r->dirs.end()) {
                r->dirs[d] = new Dir();
            }
            r = r->dirs[d];
        }
    }

    void addContentToFile(string filePath, string content) {
        auto r = root;
        vector<string> path = split(filePath, '/');
        for (int i = 0; i + 1 < path.size(); ++i) {
            r = r->dirs[path[i]];
        }
        r->files[path.back()] += content;
    }

    string readContentFromFile(string filePath) {
        Dir* r = root;
        vector<string> path = split(filePath, '/');
        for (int i = 0; i + 1 < path.size(); ++i) {
            r = r->dirs[path[i]];
        }
        return r->files[path.back()];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
int main() {
    Solution so;

    return 0;
}