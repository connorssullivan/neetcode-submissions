#include <vector>
#include <queue>

auto cmp = [](const std::vector<int>& a, const std::vector<int>& b) {
            return ((a[0] * a[0]) + (a[1] * a[1]) > (b[0] * b[0]) + (b[1] * b[1]));
        };

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmp)> minHeap(cmp);

        for (auto& p : points)
            minHeap.push(p);

        std::vector<std::vector<int>> sol;
        for (int i {}; i < k && !minHeap.empty(); i++)
        {
            std::vector<int> temp = minHeap.top();

            sol.push_back(temp);
            minHeap.pop();
        }

        return sol;
    }
};
