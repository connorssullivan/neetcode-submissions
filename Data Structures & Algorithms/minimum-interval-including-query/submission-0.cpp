class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> mins;

        for (int q : queries)
        {
            int min_query {-1};

            for (auto& i : intervals)
            {
                if (q >= i[0] && q <= i[1])
                {
                    if (min_query == -1 || min_query > i[1] - i[0])
                        min_query = i[1] - i[0] + 1;
                }
            }

            mins.push_back(min_query);
        }

        return mins;
    }
};
