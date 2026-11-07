class Twitter {
private:
    struct Node{
        int timestamp;
        int tweetId;
    };

    struct pqNode{
        int timestamp;
        int tweetId;
        int followeeId;
        int next_index;
    };

    struct ComparepqNode{
        bool operator()(const pqNode& a, const pqNode& b)
        {
            return a.timestamp < b.timestamp; // max-heap
        }
    };

    int count;
    unordered_map<int, unordered_set<int>> followMap; // userId -> set of followeeIds
    unordered_map<int, vector<Node>> tweetMap; // userId -> list of {timestamp, tweetIds}
     
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({++count, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pqNode, vector<pqNode>, ComparepqNode> pq; // 10 most recent tweets in the feed
        vector<int> ans;

        followMap[userId].insert(userId); // self posts

        for (auto followeeId : followMap[userId])
        {
            if (tweetMap.count(followeeId))
            {
                int idx = tweetMap[followeeId].size() - 1;
                auto [timestamp, tweetId] = tweetMap[followeeId][idx];

                pq.push({timestamp, tweetId, followeeId, idx - 1});
            }
        }

        while (pq.size() > 0 && ans.size() < 10)
        {
            auto [timestamp, tweetId, followeeId, nextidx] = pq.top();
            pq.pop();

            ans.push_back(tweetId);

            if (nextidx >= 0) 
            {
                auto [timestamp, tweetId] = tweetMap[followeeId][nextidx];
                pq.push({timestamp, tweetId, followeeId, nextidx - 1});
            } 
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;

        if (!followMap[followerId].count(followeeId)) return;
        followMap[followerId].erase(followeeId);
    }
};