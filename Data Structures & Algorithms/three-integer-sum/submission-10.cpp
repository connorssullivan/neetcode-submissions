class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> sol;

        sort(nums.begin(), nums.end());

        for (int i {}; i < nums.size()-2; i++)
        {
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            int left = i+1;
            int right = nums.size()-1;

            while (left < right)
            {
                int sum = nums[left] + nums[right] + nums[i];

                if (sum < 0)
                    left++;
                else if (sum > 0)
                    right--;
                else 
                {
                    sol.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }

        return sol;
    }
};
