class Solution {
public:
    int jump(vector<int>& nums) {
        int left {};
        int right {};
        int res {};

        while (right < nums.size()-1)
        {
            int farthest {};

            for (int i {left}; i <= right; i++)
                farthest = std::max(farthest, nums[i] + i);

            left = right+1;
            right = farthest;
            res++;
        }

        return res;
    }
};
