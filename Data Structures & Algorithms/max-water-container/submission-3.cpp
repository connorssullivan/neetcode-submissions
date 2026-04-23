class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left {};
        int right = heights.size() - 1;
        int max_water {};

        while (left < right)
        {
            int current_water = (right - left) * min(heights[left], heights[right]);

            max_water = max(current_water, max_water);

            if (heights[left] < heights[right])
                left++;
            else 
                right--;
        }

        return max_water;
    }
};
