class Solution {
public:
    int trap(vector<int>& height) {
        int left {};
        int right = height.size() - 1;

        int maxLeft = height[left];
        int maxRight = height[right];

        int total {};

        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (std::min(maxLeft, maxRight) - height[left] > 0)
                    total += std::min(maxLeft, maxRight) - height[left];
                left++;
                maxLeft = std::max(maxLeft, height[left]);
            }

            else
            {
                if (std::min(maxLeft, maxRight) - height[right] > 0)
                    total += std::min(maxLeft, maxRight) - height[right];
                right--;   
                maxRight = std::max(maxRight, height[right]);
            }
        }

        return total;
    }
};
