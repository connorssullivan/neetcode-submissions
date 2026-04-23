#include <vector>

class Solution {
    void dfs(std::vector<std::vector<int>>& sol, int index, const std::vector<int>& nums, std::vector<int>& current_set)
    {
        if (index >= nums.size())
        {
            sol.push_back(current_set);
            return;
        }

        current_set.push_back(nums[index]);
        dfs(sol, index+1, nums, current_set);
        current_set.pop_back();
        dfs(sol, index+1, nums, current_set);
    }
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> sol;
        std::vector<int> curr_set;

        dfs(sol, 0, nums, curr_set);

        return sol;
    }
};