#include <vector>
#include <queue>

struct ClosestPoint{
    bool operator() (vector<int> p1, vector<int> p2) const {
        double dist1 = abs(p1[0]*p1[0] + p1[1]*p1[1]);
        double dist2 = abs(p2[0]*p2[0] + p2[1]*p2[1]);

        return dist1 > dist2;
    };
};

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {

        priority_queue<vector<int>, vector<vector<int>>, ClosestPoint> pq (points.begin(), points.end());
        std::vector<std::vector<int>> sol;

        while (k && !pq.empty())
        {
            sol.push_back(pq.top());
            pq.pop();
            k--;
        }

        return sol;

    }
};
