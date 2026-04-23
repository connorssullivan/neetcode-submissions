#include <iostream>
#include <vector>
#include <algorithm> 

class Solution {

public:
    int longestConsecutive(std::vector<int>& nums) {

        if (nums.size() == 0)
            return 0;

        if (nums.size() == 1)
            return 1;

        std::sort(nums.begin(), nums.end());

        std::cout << "Sorted Nums: ";
        for (auto num : nums)
            std::cout << num << ", ";
        std::cout << "\n";

        int longest_streak {0};
        int curr_streak {0};
        bool duplicate {false};
        for (int i=0; i < nums.size() - 1; i++)
        {
            if (!duplicate)
                curr_streak++;
            
            duplicate = false;


            if (curr_streak > longest_streak)
            {
                longest_streak = curr_streak;
                // 1
                
            }

            if (nums[i+1] == nums[i])
            {
                duplicate = true;
            }

            if (nums[i+1] != nums[i] + 1 && !duplicate)
            {
                std::cout << "Stoping streak at " << nums[i] << "->" << nums[i+1] << ". Current StreaK: " << curr_streak << "\n";
                curr_streak = 0;
            }

        }

        // One more check for last number
        int last_index = nums.size() -1;
        if (nums[last_index] == nums[last_index-1] + 1)
        {
            curr_streak += 1;
            if (longest_streak < curr_streak)
                longest_streak = curr_streak;
        }

        return longest_streak;
    }
};


