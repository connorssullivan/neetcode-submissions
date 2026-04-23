class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};

        std::sort(intervals.begin(), intervals.end(), [] (const vector<int>& i1, const vector<int>& i2) {
            return i1[0] < i2[0];
        });

        vector<vector<int>> sol;

        vector<int> prev = intervals[0];

        for (int i {1}; i < intervals.size();i++)
        {
            if (intervals[i][0] <= prev[1])
                prev = {prev[0], max(prev[1], intervals[i][1])};
            
            else 
            {
                sol.push_back(prev);
                prev = intervals[i];
            }
        }

        sol.push_back(prev);
        

        return sol;
    }
};
