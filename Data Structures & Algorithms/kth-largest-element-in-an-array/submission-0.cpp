#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::less<>> maxHeap (
            std::less<>(),
            std::vector<int>(nums.begin(), nums.end())
        );

        int sol {-1};
        for (int i {}; i < k && !maxHeap.empty(); i++)
        {
            sol = maxHeap.top();
            maxHeap.pop();
        }

        return sol;
    }
};