#include <iostream>
#include <vector>
#include <algorithm> 
#include <unordered_set>

class Solution {

public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        std::unordered_set<int> nums_set {nums.begin(), nums.end()};

        int longest_streak {1};
        for (auto num : nums) 
        {
            int streak {1};
            int curr {num};

            while (nums_set.find(curr + 1) != nums_set.end())
            {
                streak++;
                curr++;
            }

            longest_streak = std::max(streak, longest_streak);
            
        }

        return longest_streak;
        
    }
};

