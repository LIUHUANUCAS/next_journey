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
class TodoList {
    struct Node {
        int task_id;
        int userId;
        string taskDescription;
        int dueDate;
        set<string> tags;
        int status;
        Node(int t = 0, int u = 0, string td = "", int due = 0, int status = 0)
            : task_id(t),
              userId(u),
              taskDescription(td),
              dueDate(due),
              status(status) {}
    };
    int task_id;

    unordered_map<int, unordered_map<int, Node>> finished;
    unordered_map<int, unordered_map<int, Node>> todo;  // user_id, task_id.

   public:
    TodoList() { task_id = 0; }

    int addTask(int userId,
                string taskDescription,
                int dueDate,
                vector<string> tags) {
        task_id++;
        Node node(task_id, userId, taskDescription, dueDate, 0);
        for_each(tags.begin(), tags.end(),
                 [&](string& s) { node.tags.insert(s); });

        todo[userId][task_id] = node;
        return task_id;
    }

    vector<string> getAllTasks(int userId) {
        if (!todo.count(userId))
            return {};
        vector<Node> list;
        for (auto it = todo[userId].begin(); it != todo[userId].end(); ++it) {
            if (it->second.status == 0) {
                list.push_back(it->second);
            }
        }
        sort(list.begin(), list.end(),
             [](Node& a, Node& b) { return a.dueDate < b.dueDate; });
        vector<string> ret;
        for_each(list.begin(), list.end(),
                 [&](Node& a) { ret.push_back(a.taskDescription); });
        return ret;
    }

    vector<string> getTasksForTag(int userId, string tag) {
        if (!todo.count(userId))
            return {};
        vector<Node> list;
        for (auto& p : todo[userId]) {
            if (p.second.status == 0 && p.second.tags.count(tag)) {
                list.push_back(p.second);
            }
        }
        sort(list.begin(), list.end(),
             [](Node& a, Node& b) { return a.dueDate < b.dueDate; });
        vector<string> ret;
        for_each(list.begin(), list.end(),
                 [&](Node& a) { ret.push_back(a.taskDescription); });
        return ret;
    }

    void completeTask(int userId, int taskId) {
        if (!todo.count(userId))
            return;
        for (auto& p : todo[userId]) {
            if (p.second.task_id == taskId && p.second.status == 0) {
                p.second.status = 1;
                todo[userId].erase(p.first);
                break;
            }
        }
    }
};

/**
 * Your TodoList object will be instantiated and called as such:
 * TodoList* obj = new TodoList();
 * int param_1 = obj->addTask(userId,taskDescription,dueDate,tags);
 * vector<string> param_2 = obj->getAllTasks(userId);
 * vector<string> param_3 = obj->getTasksForTag(userId,tag);
 * obj->completeTask(userId,taskId);
 */
int main() {
    TodoList* obj = new TodoList();
    {
        int param_1 = obj->addTask(1, "Task 1", 20231001, {"work", "urgent"});
        cout << "Added Task ID: " << param_1 << endl;
        vector<string> param_2 = obj->getAllTasks(1);
        cout << "All Tasks for User 1: ";
        for (const auto& task : param_2) {
            cout << task << ", ";
        }
        cout << endl;

        vector<string> param_3 = obj->getTasksForTag(1, "urgent");
        cout << "Tasks with tag 'urgent': ";
        for (const auto& task : param_3) {
            cout << task << ", ";
        }
        cout << endl;

        obj->completeTask(1, 1);
        cout << "Completed Task ID 1" << endl;

        vector<string> param_4 = obj->getAllTasks(1);
        cout << "All Tasks for User 1 after completion: ";
        for (const auto& task : param_4) {
            cout << task << ", ";
        }
        cout << endl;
    }

    return 0;
}