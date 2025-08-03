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
class Facebook {
    struct Post {
        int user_id;
        int post_time;
        string post_content;
        Post() {}
        Post(int userId, int postTime, string postContent)
            : user_id(userId), post_time(postTime), post_content(postContent) {}
    };
    // [tweet_id, time]
    unordered_map<int, list<Post>> user_post;
    unordered_map<int, unordered_set<int>> follow;
    int time;

   public:
    Facebook() { time = 0; }

    void writePost(int userId, string postContent) {
        Post post = Post(userId, ++time, postContent);
        user_post[userId].push_front(post);
    }

    void addFriend(int user1, int user2) {
        if (user1 == user2)
            return;
        follow[user1].insert(user2);
        follow[user2].insert(user1);
    }

    vector<string> showPosts(int userId) {
        vector<string> ret;
        auto cmp = [](const Post& a, const Post& b) {
            return a.post_time > b.post_time;
        };
        priority_queue<Post, vector<Post>, decltype(cmp)> pq(cmp);
        for (auto u : follow[userId]) {
            for (auto& node : user_post[u]) {
                pq.push(node);
            }
        }
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            ret.push_back(x.post_content);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

/**
 * Your Facebook object will be instantiated and called as such:
 * Facebook* obj = new Facebook();
 * obj->writePost(userId,postContent);
 * obj->addFriend(user1,user2);
 * vector<string> param_3 = obj->showPosts(userId);
 */
int main() {
    Facebook fb;
    {
        fb.writePost(1, "Hello World");
        fb.writePost(2, "Hello Facebook");
        fb.addFriend(1, 2);
        auto posts = fb.showPosts(1);
        printvector(posts);
    }
    return 0;
}