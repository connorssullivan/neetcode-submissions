#include <vector>
#include <iostream>
#include <set>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> sol;

        std::sort(nums.begin(), nums.end());

        auto dfs = [&](auto&& self, int index) {
            if (index >= nums.size() - 2) 
                return;
            while (index > 0 && nums[index] == nums[index-1])
                index++;
            

            int l {index+1};
            int r = nums.size()-1;
            
            while (l < r)
            {
                int total = nums[l] + nums[r] + nums[index];
                if (total == 0)
                {
                    std::vector<int> curr {nums[l], nums[r], nums[index]};
                    sol.push_back(curr);

                    while (l < r && nums[l] == nums[l + 1]) 
                        l++;
                    
                    while (l < r && nums[r] == nums[r - 1]) 
                        r--;
                    l++;
                    r--;
                }

                else if (total < 0)
                {
                    l++;
                }

                else 
                {
                    r--;
                }
            }
            self(self, index+1);
        };
        dfs(dfs, 0);

        return sol;
    }

    
};
