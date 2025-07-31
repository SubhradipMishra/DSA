#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

class Twitter {
private:
    int timeStamp = 0;

    struct Tweet {
        int id;
        int time;
        Tweet(int tweetId, int t) : id(tweetId), time(t) {}
    };

    // user -> list of tweets
    unordered_map<int, vector<Tweet>> userTweets;

    // follower -> set of followees
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        userTweets[userId].emplace_back(tweetId, timeStamp++);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;

        // Include own tweets
        following[userId].insert(userId);

        for (int followee : following[userId]) {
            for (auto& tweet : userTweets[followee]) {
                maxHeap.push({tweet.time, tweet.id});
            }
        }

        vector<int> feed;
        int count = 0;
        while (!maxHeap.empty() && count < 10) {
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // can't follow yourself
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // can't unfollow yourself
        following[followerId].erase(followeeId);
    }
};
