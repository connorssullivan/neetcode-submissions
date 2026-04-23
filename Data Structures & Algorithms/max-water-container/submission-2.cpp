class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left {};
        int right = heights.size() - 1;
        int max_water {};

        while (left < right)
        {
            int water = std::min(heights[left], heights[right]) * ((right - left));

            max_water = max(water, max_water);
            
            if (heights[left] <= heights[right])
                left++;
            else
                right--;
        }


        return max_water;
    }
};
