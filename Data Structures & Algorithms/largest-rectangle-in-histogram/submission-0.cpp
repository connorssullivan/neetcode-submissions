#include <vector>
#include <iostream>
#include <stack>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> s;
        int max_area {0};
        int n = heights.size();

        for (int i=0; i <= n; i++)
        {
            while (!s.empty() && (i == n || heights[s.top()] >= heights[i]))
            {
                int height = heights[s.top()];
                s.pop();
                int width = (s.empty() ? i : i - s.top() - 1);
                max_area = std::max(max_area, height*width);
            }
            s.push(i);
        }

        return max_area;

    }
};
