#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> sol;
        std::vector<int> curr_set;

        auto dfs = [&] (auto&& self, int index) {
            if (index >= nums.size())
            {
                sol.push_back(curr_set);
                return;
            }

            curr_set.push_back(nums[index]);
            self(self, index+1);
            curr_set.pop_back();
            self(self, index+1);
        };

        dfs(dfs, 0);

        return sol;
    }
};