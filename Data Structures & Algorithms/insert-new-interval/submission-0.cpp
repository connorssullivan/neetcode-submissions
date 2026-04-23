class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int new_start = newInterval[0];
        int new_end = newInterval[1];
        std::vector<std::vector<int>> sol;
        
        for (int i {}; i < intervals.size();i++)
        {
            if (intervals[i][0] > new_end)
            {
                sol.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(sol));
                return sol;
            }

            else if (new_start > intervals[i][1])
            {
                sol.push_back(intervals[i]);
            }

            else
            {
                newInterval[0] = std::min(intervals[i][0], newInterval[0]);
                newInterval[1] = std::max(intervals[i][1], newInterval[1]);
            }
        }

        sol.push_back(newInterval);
        return sol;
            
    }
};
