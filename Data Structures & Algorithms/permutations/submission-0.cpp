#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        if (nums.size() < 1)
            return {{}};

        std::vector<int> curr(nums.begin()+1, nums.end());
        std::vector<std::vector<int>> perm = permute(curr);
        std::vector<std::vector<int>> res;

        for (const auto& p : perm)
        {
            for (int i {}; i <= p.size(); i++)
            {
                std::vector<int> temp = p;
                temp.insert(temp.begin()+i, nums[0]);
                res.push_back(temp);
            }
        }

        return res;
    }
};
