#include <vector>


class Solution {
public:
    int findMin(std::vector<int> &nums) {
        int left {0};
        int right = nums.size() -1;

        int smallest = nums[left];

        while (left <= right)
        {
            int mid = left + ((right - left) / 2);

            smallest = std::min(nums[mid], smallest);

            // If out of order
            if (nums[left] >= nums[right])
            {
                if (nums[mid] >= nums[left])
                    left = mid+1;
                else 
                    right = mid-1;
            }

            // Normal Search
            else 
            {
                smallest = std::min(nums[left], smallest);
                break;
            }
        }

        return smallest;
    }
};
