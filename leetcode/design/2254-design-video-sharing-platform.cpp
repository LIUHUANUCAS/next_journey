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
class VideoSharingPlatform {
    int video_id;                               // id;
    set<int> removed_id_set;                    // remove video id set.
    unordered_map<int, pair<int, int>> record;  // video_id:[like,dislike]
    unordered_map<int, pair<int, string>>
        video_content;  // video_id: [watch_time,video_content]

   public:
    VideoSharingPlatform() { video_id = 0; }

    int upload(string video) {
        int id = video_id;
        if (!removed_id_set.empty()) {
            id = *removed_id_set.begin();
            removed_id_set.erase(id);
        } else {
            id = video_id++;
        }

        record[id] = {0, 0};
        video_content[id] = {0, video};
        return id;
    }

    void remove(int videoId) {
        if (!video_content.count(videoId))
            return;
        record.erase(videoId);
        video_content.erase(videoId);
        removed_id_set.insert(videoId);
    }

    string watch(int videoId, int startMinute, int endMinute) {
        if (!video_content.count(videoId))
            return "-1";
        video_content[videoId].first++;
        string& str = video_content[videoId].second;
        return string(str.begin() + startMinute,
                      str.begin() + min((int)str.length(), endMinute + 1));
    }

    void like(int videoId) {
        if (!record.count(videoId))
            return;
        record[videoId].first++;
    }

    void dislike(int videoId) {
        if (!record.count(videoId))
            return;
        record[videoId].second++;
    }

    vector<int> getLikesAndDislikes(int videoId) {
        if (!record.count(videoId))
            return {-1};
        return {record[videoId].first, record[videoId].second};
    }

    int getViews(int videoId) {
        if (!video_content.count(videoId))
            return -1;
        return video_content[videoId].first;
    }
};

/**
 * Your VideoSharingPlatform object will be instantiated and called as such:
 * VideoSharingPlatform* obj = new VideoSharingPlatform();
 * int param_1 = obj->upload(video);
 * obj->remove(videoId);
 * string param_3 = obj->watch(videoId,startMinute,endMinute);
 * obj->like(videoId);
 * obj->dislike(videoId);
 * vector<int> param_6 = obj->getLikesAndDislikes(videoId);
 * int param_7 = obj->getViews(videoId);
 */
int main() {
    VideoSharingPlatform* obj = new VideoSharingPlatform();
    {
        int param_1 = obj->upload("HelloWorld");
        cout << "Upload video id: " << param_1 << endl;
        obj->like(param_1);
        obj->dislike(param_1);
        vector<int> likes_dislikes = obj->getLikesAndDislikes(param_1);
        cout << "Likes: " << likes_dislikes[0]
             << ", Dislikes: " << likes_dislikes[1] << endl;
        string watched_content = obj->watch(param_1, 0, 4);
        cout << "Watched content: " << watched_content << endl;
        int views = obj->getViews(param_1);
        cout << "Views: " << views << endl;
    }
    {
        int param_2 = obj->upload("AnotherVideo");
        cout << "Upload video id: " << param_2 << endl;
    }
    {
        obj->remove(0);
        cout << "Removed video id 0" << endl;
    }

    return 0;
}