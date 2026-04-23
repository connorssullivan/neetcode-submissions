struct eval 
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }

};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, eval> pq;

        unordered_map<int, int> mp;
        for (const auto num : nums)
        {
            if (!mp.count(num))
                mp[num] = 0;
            mp[num]++;
        }

        for (const auto& p : mp)
            pq.push(p);
        
        vector<int> sol;
        for (int i {}; i < k && !pq.empty(); i++)
        {
            int temp = pq.top().first;
            pq.pop();

            sol.push_back(temp);
        }

        return sol;
    }
};
