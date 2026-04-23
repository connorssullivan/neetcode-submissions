class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto find_closest = [] (const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(find_closest)> closest(find_closest);

        for (int i {}; i < points.size(); i++)
        {
            closest.push({i, points[i][0]*points[i][0] + points[i][1]*points[i][1] });
        }

        while (closest.size() > k)
            closest.pop();

        vector<vector<int>> ans;
        while (closest.size() > 0)
        {
            ans.push_back(points[closest.top().first]);
            closest.pop();
        }

        return ans;

    }
};
