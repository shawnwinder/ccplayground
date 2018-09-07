// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
 * [355] Design Twitter
 *
 * https://leetcode.com/problems/design-twitter/description/
 *
 * algorithms
 * Medium (26.12%)
 * Total Accepted:    27.7K
 * Total Submissions: 106.1K
 * Testcase Example:
 * '["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]'
 *
 * Design a simplified version of Twitter where users can post tweets,
 * follow/unfollow another user and is able to see the 10 most recent tweets in
 * the user's news feed. Your design should support the following methods:
 *
 *
 *
 * postTweet(userId, tweetId): Compose a new tweet.
 * getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's
 * news feed. Each item in the news feed must be posted by users who the user
 * followed or by the user herself. Tweets must be ordered from most recent to
 * least recent.
 * follow(followerId, followeeId): Follower follows a followee.
 * unfollow(followerId, followeeId): Follower unfollows a followee.
 *
 *
 *
 * Example:
 *
 * Twitter twitter = new Twitter();
 *
 * // User 1 posts a new tweet (id = 5).
 * twitter.postTweet(1, 5);
 *
 * // User 1's news feed should return a list with 1 tweet id -> [5].
 * twitter.getNewsFeed(1);
 *
 * // User 1 follows user 2.
 * twitter.follow(1, 2);
 *
 * // User 2 posts a new tweet (id = 6).
 * twitter.postTweet(2, 6);
 *
 * // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
 * // Tweet id 6 should precede tweet id 5 because it is posted after tweet id
 * 5.
 * twitter.getNewsFeed(1);
 *
 * // User 1 unfollows user 2.
 * twitter.unfollow(1, 2);
 *
 * // User 1's news feed should return a list with 1 tweet id -> [5],
 * // since user 1 is no longer following user 2.
 * twitter.getNewsFeed(1);
 *
 *
 */
class Twitter {
    struct Tweet {
        int time;
        int id;
        Tweet(int time, int id)
            : time(time)
            , id(id) {}
    };
    unordered_map<int, vector<Tweet>> tweets; // [u] = array of tweets by u
    unordered_map<int, unordered_set<int>> following; // [u] = array of users followed by u
    int time;

public:
    Twitter()
        : time(0) {}

    void postTweet(int userId, int tweetId) { tweets[userId].emplace_back(time++, tweetId); }

    vector<int> getNewsFeed(int userId) {
        vector<pair<Tweet*, Tweet*>> h; // pair of pointers (begin, current)

        for (auto& u : following[userId]) {
            auto& t = tweets[u];
            if (t.size() > 0)
                h.emplace_back(t.data(), t.data() + t.size() - 1);
        }
        auto& t = tweets[userId]; // self
        if (t.size() > 0)
            h.emplace_back(t.data(), t.data() + t.size() - 1);

        auto f = [](const pair<Tweet*, Tweet*>& x, const pair<Tweet*, Tweet*>& y) {
            return x.second->time < y.second->time;
        };
        make_heap(h.begin(), h.end(), f);

        const int n = 10;
        vector<int> o;
        o.reserve(n);
        for (int i = 0; (i < n) && !h.empty(); ++i) {
            pop_heap(h.begin(), h.end(), f);

            auto& hb = h.back();
            o.push_back(hb.second->id);

            if (hb.first == hb.second--)
                h.pop_back();
            else
                push_heap(h.begin(), h.end(), f);
        }
        return o;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) { following[followerId].erase(followeeId); }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

int mymain(int argc, char* argv[]) { return 0; }
