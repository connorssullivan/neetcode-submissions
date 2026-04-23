#include <vector>


class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left {0};
        int right {static_cast<int>(nums.size() - 1)};

        while (left <= right)
        {
            int mid {(right + left) / 2};

            if (nums[mid] == target)
                return mid;

            else if (nums[mid] > target)
                right = mid - 1;

            else left = mid + 1;
            
        }

        return -1;

    }
};
