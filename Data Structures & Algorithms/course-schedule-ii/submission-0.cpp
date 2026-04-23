class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> sol;

        unordered_map<int, vector<int>> preReqMap;
        for (auto& p : prerequisites)
            preReqMap[p[0]].push_back(p[1]); 

        unordered_set<int> visted;
        unordered_set<int> visiting;

        auto dfs = [&] (auto&& self, int course) {
            if (visiting.count(course))
                return false;
            
            if (visted.count(course))
                return true;
            
            visiting.insert(course);
            if (preReqMap.count(course))
            {
                for (int p : preReqMap[course])
                {
                    if (!self(self, p))
                        return false;
                }
            }

            visiting.erase(course);
            visted.insert(course);
            sol.push_back(course);

            return true;
        };

        for (int i {}; i < numCourses; i++)
        {
            if (!dfs(dfs, i))
                return {};
        }

        return sol;
    }
};
