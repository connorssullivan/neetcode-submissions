class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> sol;    
        std::vector<int> curr;
        
        std::sort(nums.begin(), nums.end());

        auto dfs = [&] (auto&& self, int index)
        {
            if (index >= nums.size())
            {
                sol.push_back(curr);
                return;
            }

            curr.push_back(nums[index]);
            self(self, index+1);
            curr.pop_back();
            
            while (index < nums.size() && nums[index] == nums[index+1])
                index++;

            self(self, index+1);

        };

        dfs(dfs, 0);
        return sol;
    }
};
