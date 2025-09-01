#include <algorithm>
#include <cstdarg>
#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;
#define DEBUG 1
static int Debug = 0;

// // Definition for a Node.
// struct Node {
//     int val;
//     Node* next;
//     Node* random;
//     Node(int _val = 0) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    // TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l = nullptr, TreeNode* r = nullptr)
        : val(x), left(l), right(r) {}

    static TreeNode* create_tree(vector<int>& A) {
        int k = 0;
        return create_tree(A, k);
    }

    static TreeNode* create_tree(string& res) {
        replace(res.begin(), res.end(), ',', ' ');
        res = string(res.begin() + 1, res.end() - 1);
        // cout << "input:" << res << endl;
        return deserialize(res);
    }

    static TreeNode* create_tree(vector<int>& A, int& i) {
        int n = A.size();
        if (i >= n)
            return nullptr;
        auto root = new TreeNode(A[i]);
        if ((++i) < n) {
            root->left = new TreeNode(A[i]);
        }
        if ((++i) < n) {
            root->right = new TreeNode(A[i]);
        }
        root->left = create_tree(A, i);
        root->right = create_tree(A, i);
        return root;
    }

    static TreeNode* decode(string& str) {
        if (str.empty() || str == "null")
            return nullptr;
        stringstream sst;
        sst << str;
        int v;
        sst >> v;
        return new TreeNode(v);
    }

    // Decodes your encoded data to tree.
    static TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;
        stringstream ss;
        ss << data;
        queue<TreeNode*> que;
        string str;

        ss >> str;
        TreeNode* root = decode(str);
        if (root == nullptr)
            return root;
        que.push(root);
        TreeNode* r;
        while (!que.empty() && !ss.eof()) {
            r = que.front();
            que.pop();
            ss >> str;
            auto x = decode(str);
            if (x) {
                r->left = x;
                que.push(x);
            }
            if (ss.eof())
                break;
            ss >> str;
            x = decode(str);
            if (x) {
                r->right = x;
                que.push(x);
            }
        }
        return root;
    }

    // Encodes a tree to a single string.
    static string serialize(TreeNode* root) { return level_order_encode(root); }
    static string encode(TreeNode* p) {
        if (p == nullptr)
            return "null";
        return to_string(p->val);
    }

    // [1,2,3,null,null,4,5]
    static string level_order_encode(TreeNode* root) {
        if (root == nullptr)
            return "null";
        string str;
        stringstream ss;
        queue<TreeNode*> que;
        que.push(root);
        stringstream sline;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto node = que.front();
                que.pop();
                auto x = node;
                str = encode(node);
                // cout << "str:" << str << endl;
                ss << str + " ";
                if (node == nullptr) {
                    continue;
                }
                que.push(node->left);
                que.push(node->right);
            }
        }
        return ss.str();
    }
};

bool sameTree(TreeNode* A, TreeNode* B) {
    if (A == nullptr && B == nullptr)
        return 1;
    if (A == nullptr || B == nullptr)
        return 0;
    return A->val == B->val && sameTree(A->left, B->left) &&
           sameTree(A->right, B->right);
}

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = 0) : val(x), next(NULL) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
    static ListNode* create_list(vector<int>& A) {
        ListNode dumpy(0);
        ListNode* p = &dumpy;
        for (auto v : A) {
            p->next = new ListNode(v);
            p = p->next;
        }
        return dumpy.next;
    }
    static ListNode* create_list(vector<int> A) {
        ListNode dumpy(0);
        ListNode* p = &dumpy;
        for (auto v : A) {
            p->next = new ListNode(v);
            p = p->next;
        }
        return dumpy.next;
    }
};

ListNode* create_linked_list(vector<int> A) {
    ListNode dumpy(0);
    ListNode* p = &dumpy;
    for (auto v : A) {
        p->next = new ListNode(v);
        p = p->next;
    }
    return dumpy.next;
}

vector<ListNode*> create_linked_list(vector<vector<int>>& A) {
    vector<ListNode*> lists;
    for (auto& v : A) {
        ListNode* p = create_linked_list(v);
        lists.push_back(p);
    }
    return lists;
}

ListNode* get_linked_list_node(ListNode* head, int index) {
    if (head == nullptr)
        return nullptr;
    auto p = head;
    while (--index > 0 && p != nullptr) {
        p = p->next;
    }
    return p;
}
struct StringType {
    string key;
    int idx;
    StringType(string k = "", int i = 0) : key(k), idx(i) {}
    int Key() { return idx; }
    string getkey() { return key; }
    string String() { return key + ":" + to_string(idx); }
};

void print_list(ListNode* p) {
    cout << "[ ";
    for (; p != nullptr; p = p->next) {
        cout << p->val;
        if (p->next)
            cout << " ";
    }
    cout << "]" << endl;
}

void print_linked_list(ListNode* p) {
    print_list(p);
}

void printvector_index(vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (auto e : array) {
        cout << e << " ";
    }
    cout << endl;
}

void printvector(vector<int>& array, int lo, int hi) {
    cout << "{";
    for (int i = lo; i < hi; ++i) {
        cout << array[i];
        if (i != hi - 1)
            cout << ", ";
    }
    cout << "}" << endl;
}

template <class Interator>
void printvector(Interator begin, Interator end) {
    cout << "{";
    for (auto it = begin; it != end; ++it) {
        cout << *it << (it + 1 != end ? ", " : "");
    }
    cout << "}" << endl;
}

template <typename T>
void printvector(vector<T>& array, int indent = 0) {
    cout << string(indent, ' ');
    cout << "[";
    for (auto it = array.begin(); it != array.end(); ++it) {
        cout << *it << (it + 1 != array.end() ? "," : "");
    }

    cout << "]" << endl;
}

template <typename T, typename S>
void printmap(unordered_map<T, S>& umap) {
    cout << "{";
    for (auto it = umap.begin(); it != umap.end(); ++it) {
        cout << "[" << it->first << ":" << it->second << "] ";
    }
    cout << "}" << endl;
}

template <typename T>
void printvector(vector<vector<T>>& array) {
    if (array.empty()) {
        cout << "[]" << endl;
        return;
    }
    cout << "[\n";
    for (auto& e : array) {
        printvector(e, 3);
    }
    cout << "]" << endl;
}

void print_tree(TreeNode* p, int x) {
    if (p == nullptr) {
        return;
    }
    print_tree(p->left, x);
    cout << p->val << " ";
    print_tree(p->right, x);
}

void print_tree_preorder(TreeNode* p) {
    if (p == nullptr) {
        return;
    }
    cout << p->val << " ";
    print_tree_preorder(p->left);
    print_tree_preorder(p->right);
}

void preorder_tree(TreeNode* p) {
    print_tree_preorder(p);
    cout << endl;
}

void print_tree(TreeNode* p) {
    print_tree(p, 0);
    cout << endl;
}

void print_tree_level(TreeNode* p) {
    if (p == nullptr)
        return;
    queue<TreeNode*> que;
    que.push(p);
    int l = 0;
    while (!que.empty()) {
        l++;
        cout << "level-" << l << " ";
        int size = que.size();
        for (int i = 0; i < size; i++) {
            auto x = que.front();
            que.pop();
            cout << x->val << " ";
            if (x->left) {
                que.push(x->left);
            }
            if (x->right)
                que.push(x->right);
        }
        cout << endl;
    }
}

void setDebug() {
    Debug = 1;
}

void println(const char* format, ...) {
    if (!Debug) {
        return;
    }
    va_list ap;
    va_start(ap, format);
    vprintf(format, ap);
    va_end(ap);
    printf("\n");
}
