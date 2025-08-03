#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
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
class Twitter {
    // user_id ->{tweetid1,tweetid}
    unordered_map<int, list<tuple<int, int>>> user_post;
    // user_id following {user_id1,user_id2}
    unordered_map<int, unordered_set<int>> follow_list;
    int time;
    const int max_size = 10;

   public:
    Twitter() {
        user_post.clear();
        follow_list.clear();
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        user_post[userId].push_front({++time, tweetId});
        if (user_post[userId].size() > max_size)
            user_post[userId].pop_back();
    }

    vector<int> getNewsFeed(int userId) {
        auto cmp = [](tuple<int, int>& a, tuple<int, int>& b) {
            return get<0>(a) > get<0>(b);
        };
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, decltype(cmp)>
            pq(cmp);

        for (auto& t : user_post[userId]) {
            pq.push(t);
        }
        for (auto u : follow_list[userId]) {
            if (u == userId)
                continue;
            for (auto& t : user_post[u]) {
                pq.push(t);
                if (pq.size() > max_size)
                    pq.pop();
            }
        }
        vector<int> ret;
        while (!pq.empty()) {
            auto [timestamp, tid] = pq.top();
            pq.pop();
            ret.push_back(tid);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    void follow(int followerId, int followeeId) {
        follow_list[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follow_list[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
int main() {
    Twitter* twitter = new Twitter();
    {
        twitter->postTweet(1, 5);
        auto ret = twitter->getNewsFeed(1);
        printvector(ret);  // [5]
    }
    {
        twitter->follow(1, 2);
        twitter->postTweet(2, 6);
        auto ret = twitter->getNewsFeed(1);
        printvector(ret);  // [6,5]
    }
    {
        twitter->unfollow(1, 2);
        auto ret = twitter->getNewsFeed(1);
        printvector(ret);  // [5]
    }
    return 0;
}