class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> classes (numCourses);
        for (const auto& p : prerequisites)
        {
            classes[p[0]].insert(p[1]);
        }


        unordered_set<int> seen;

        auto dfs = [&] (auto&& self, const int curr) -> bool {
            if (seen.count(curr))
                return false;
            if (classes[curr].empty())
                return true;

            seen.insert(curr);
            for (int c : classes[curr])
            {
                if (!self(self, c)) return false;
            }

            seen.erase(curr);
            classes[curr].clear();
            return true;
        };

        for (int i {}; i < numCourses; i++)
        {
            bool curr = dfs(dfs, i);
            if (!curr)
                return false;
        }

        return true;
        
    }
};
