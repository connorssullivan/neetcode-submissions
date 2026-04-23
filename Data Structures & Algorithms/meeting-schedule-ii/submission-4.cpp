/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;

        for (const Interval& i : intervals)
        {
            start.push_back(i.start);
            end.push_back(i.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int s {};
        int e {};
        int res {};
        int count {};

        while (s < intervals.size())
        {
            if (start[s] < end[e])
            {
                s++;
                count++;
            }

            else 
            {
                e++;
                count--;
            }

            res = max(res, count);
        }

        return res;

    }
};




