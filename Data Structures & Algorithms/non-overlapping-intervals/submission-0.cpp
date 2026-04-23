class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& i1, vector<int>& i2) {
            return i1[0] < i2[0];
        });

        int removed {};
        int prev_end = intervals[0][1];

        for (int i {1}; i < intervals.size(); i++)
        {
            if (prev_end > intervals[i][0])
            {
                removed++;
                prev_end = min(prev_end, intervals[i][1]);
            }

            else 
            {
                prev_end = intervals[i][1];
            }
        }

        return removed;
    }
};
