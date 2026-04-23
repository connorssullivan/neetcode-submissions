class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        unordered_set<int> visted;

        for (int i {}; i < numCourses; i++)
            mp[i] = {};
        
        for (auto& p : prerequisites)
            mp[p[0]].push_back(p[1]);
        
        auto dfs = [&](auto&& self, int curr) -> bool{
            if (visted.count(curr))
                return false;
            
            if (mp[curr].empty())
                return true;
            
            visted.insert(curr);
            for (int pre : mp[curr])
            {
                if (!self(self, pre))
                    return false;
            }

            visted.erase(curr);
            mp[curr].clear();
            return true;
        };

        for (int i {}; i < numCourses; i++)
            if (!dfs(dfs, i))
                return false;
            
            return true;
    }
};
