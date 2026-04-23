#include <vector>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        
        std::vector<int> sol{};

        int left {0};
        int right {0};
        int curr_max_index {left};

        while (right < nums.size())
        {
            if (right == left)
            {
                curr_max_index = left;
            }

            if (nums[right] > nums[curr_max_index])
            {
                curr_max_index = right;
            }

            if (right - left + 1 == k)
            {
                sol.push_back(nums[curr_max_index]);
                if (curr_max_index == left)
                {
                    right = left;
                }
                left++;

            }

            right++;
        }

        return sol;
    }
};
