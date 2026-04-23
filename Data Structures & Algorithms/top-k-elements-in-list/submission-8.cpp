class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    
        std::unordered_map<int, int> counts;

        auto fun = [&] (std::pair<int, int> p1, std::pair<int, int> p2) {
            return p1.second < p2.second;
        };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(fun)> pq(fun);
        std::vector<int> sol;

        for (int num : nums)
            counts[num]++;
        
        for (std::pair<int, int> p : counts)
        {
            pq.push(p);
            std::cout << p.first << "=" << p.second << "\n";
        }

        while (!pq.empty() && k > 0)
        {
            auto mostFrequent = pq.top(); pq.pop();
            sol.push_back(mostFrequent.first);
            k--;
        }

        return sol;
    }
};
