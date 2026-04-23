#include <vector>
#include <queue>
class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::vector<int> count(26,0);
        
        for (char t : tasks)
        {
            count[t - 'A']++;
        }

        sort(count.begin(), count.end());
        int maxF = count[25];
        int idle = (maxF - 1) * n;

        for (int i = 24; i >= 0; i--)
            idle -= std::min(maxF-1, count[i]);

        return std::max(0, idle) + tasks.size();

    }
};