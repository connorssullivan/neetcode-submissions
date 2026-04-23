class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    
        std::unordered_map<int, int> counts;
        std::vector<std::vector<int>> freq(nums.size()+1);

        std::vector<int> sol;

        for (int num : nums)
            counts[num]++;
        
        for (std::pair<int, int> p : counts)
            freq[p.second].push_back(p.first);

        for (int i {freq.size()-1}; i > -1; i--)
        {
            for (int j {}; j < freq[i].size(); j++)
            {
                sol.push_back(freq[i][j]);

                if (sol.size() == k)
                    return sol;
            }
        }
    }
};
