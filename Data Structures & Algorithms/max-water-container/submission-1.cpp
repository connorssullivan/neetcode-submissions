class Solution {

public:
    int maxArea(std::vector<int>& heights) {
        int max_area { 0 };
        int left {0};
        int right { static_cast<int> (heights.size()-1) };

        while (left < right)
        {
            int area {0};
            area = std::min(heights[left], heights[right]) * ((right - left));

            max_area = std::max(area, max_area);

            if (heights[left] < heights[right])
                left++;
            else right--;
        }

        return max_area;
        
    }
};