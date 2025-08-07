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

class TextEditor {
    deque<char> start, end;

   public:
    TextEditor() {}

    void addText(string text) {
        for (auto c : text)
            start.push_back(c);
    }
    int deleteText(int k) {
        int ret = min(k, (int)start.size());
        for (int i = 0; i < ret; ++i) {
            start.pop_back();
        }
        return ret;
    }

    string cursorLeft(int k) {
        int ret = min(k, (int)start.size());
        for (int i = 0; i < ret; ++i) {
            end.push_front(start.back());
            start.pop_back();
        }

        string str;
        for (auto it = start.rbegin(); it != start.rend() && str.size() < 10;
             ++it) {
            str.push_back(*it);
        }
        reverse(str.begin(), str.end());
        return str;
    }

    string cursorRight(int k) {
        int ret = min(k, (int)end.size());
        for (int i = 0; i < ret; ++i) {
            start.push_back(end.front());
            end.pop_front();
        }
        string str;
        for (auto it = start.rbegin(); it != start.rend() && str.size() < 10;
             ++it) {
            str.push_back(*it);
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

int main() {
    TextEditor* obj = new TextEditor();
    {
        obj->addText("leetcode");
        cout << obj->cursorLeft(4) << endl;   // 返回 "leet"
        cout << obj->deleteText(2) << endl;   // 返回 2
        cout << obj->cursorLeft(2) << endl;   // 返回 "le"
        cout << obj->cursorRight(3) << endl;  // 返回 "leet"
        cout << obj->deleteText(4) << endl;   // 返回 2
        cout << obj->cursorLeft(2) << endl;   // 返回 "le"
        cout << obj->cursorRight(2) << endl;  // 返回 "leet"
        obj->addText("code");
        cout << obj->cursorLeft(4) << endl;  // 返回 "leet"
        cout << obj->deleteText(4) << endl;  // 返回 4
    }

    return 0;
}