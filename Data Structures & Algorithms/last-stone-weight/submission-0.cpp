#include <vector>
#include <queue>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int, std::vector<int>, std::less<int>> maxQ;

        for (int stone : stones)
            maxQ.push(stone);

        while (maxQ.size() > 1)
        {
            int biggest = maxQ.top();
            maxQ.pop();
            int second_biggest = maxQ.top();
            maxQ.pop();

            if (biggest > second_biggest)
                maxQ.push(biggest-second_biggest);
        }

        maxQ.push(0);

        return maxQ.top();
    }
};