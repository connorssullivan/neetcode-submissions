class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        unordered_set<int> good;
        
        for (auto& t : triplets)
        {
            bool is_valid = true;
            for (int i {}; i < t.size(); i++)
            {
                if (target[i] < t[i])
                {
                    is_valid = false;
                    break;
                }
            }

            if (is_valid)
            {
                for (int i {}; i < t.size(); i++)
                {
                    if (t[i] == target[i])
                        good.insert(i);
                }
            }

        }

        return good.size() == 3;
    }
};
