class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cache(nums.size(), 1);

        for (int i = nums.size()-1; i >= 0; i--)
        {
            for (int j = i +1; j < nums.size(); j++)
            {
                if (nums[i] < nums[j])
                    cache[i] = max(cache[i], cache[j]+1);
            }
        }

        return *max_element(cache.begin(), cache.end());
    }
};
