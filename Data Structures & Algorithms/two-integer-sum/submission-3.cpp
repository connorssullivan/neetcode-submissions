class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> prev;

        for (int i {}; i < nums.size(); i++)
        {
            int diff = target - nums[i];

            if (prev.count(diff))
                return {prev[diff], i};
            
            prev[nums[i]] = i;
        }

    }
};
