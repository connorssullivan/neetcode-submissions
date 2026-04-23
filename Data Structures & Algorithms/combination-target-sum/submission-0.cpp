#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> sol;
        std::vector<int> curr_set;
        int count {};

        auto dfs = [&](auto&& self, int index) {
            
            if (count == target)
            {
                sol.push_back(curr_set);
                return;
            }

            if (count > target)
                return;

            if (index >= nums.size())
            {
                return;
            }

            
            
            
            count += nums[index];
            curr_set.push_back(nums[index]);
            self(self, index);

            count -= nums[index];
            curr_set.pop_back();
            
            self(self, index+1);

        };
        
        dfs(dfs,0);
        return sol;
    }
};
