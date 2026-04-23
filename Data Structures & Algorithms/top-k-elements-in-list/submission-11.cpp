class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto lam = [] (pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(lam)> pq(lam);

        unordered_map<int, int> counts;

        for (int i : nums)
            counts[i]++;

        for (auto& p : counts)
            pq.push(p);

        vector<int> sol;
        while (k > 0)
        {
            sol.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        
        return sol;
    }
};
