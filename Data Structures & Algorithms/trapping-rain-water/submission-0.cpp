#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        if (height.size() == 0)
                return 0;

            int total_rain {0};
            int r = height.size()-1;
            int l {0};
            int left_max {height[l]};
            int right_max {height[r]};
            

            while (l < r)
            {

                if (left_max < right_max)
                {
                    l++;
                    left_max = std::max(height[l], left_max);
                    total_rain += left_max - height[l];
                }else {
                    r--;
                    right_max = std::max(height[r], right_max);
                    total_rain += right_max - height[r];
                }
            }

            return total_rain;
    }
};



