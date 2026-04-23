#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

class Twitter {
private:
    int count;
    std::unordered_map<int, std::set<int>> followMap;
    std::unordered_map<int, std::vector<std::vector<int>>> tweetMap;

public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId});
    }
    
    std::vector<int> getNewsFeed(int userId) {
        std::vector<int> sol;

        auto compare = [](const std::vector<int>& a, const std::vector<int>& b){
            return a[0] < b[0];
        };

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare)> minHeap(compare);

        followMap[userId].insert(userId);

        for (int followId : followMap[userId])
        {
            if (tweetMap.count(followId))
            {
                const std::vector<std::vector<int>>& tweets = tweetMap[followId];
                int index = tweets.size() - 1;
                minHeap.push({tweets[index][0], tweets[index][1], followId, index});
            }   
        }

        while (!minHeap.empty() && sol.size() < 10)
        {
            std::vector<int> curr = minHeap.top();
            minHeap.pop();
            sol.push_back(curr[1]);
            int index = curr[3];
            if (index > 0)
            {
                const std::vector<int>& tweet = tweetMap[curr[2]][index-1];
                minHeap.push({tweet[0], tweet[1], curr[2], index-1});
            }
        }

        return sol;

    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
