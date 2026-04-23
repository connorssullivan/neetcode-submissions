class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;

        sort(tickets.begin(), tickets.end());
        for (auto& ticket : tickets)
            adj[ticket[0]].push_back(ticket[1]);

        vector<string> res;
        res.emplace_back("JFK");

        auto dfs = [&] ( auto&& self, const string& src) {
            if (res.size() == tickets.size() + 1)
                return true;

            if (adj.find(src) == adj.end())
                return false;

            vector<string>& temp = adj[src];
            for (int i {}; i < temp.size(); i++)
            {
                string curr = temp[i];
                adj[src].erase(adj[src].begin() + i);
                res.push_back(curr);

                if (self(self, curr))
                    return true;

                adj[src].insert(adj[src].begin() + i, curr);
                res.pop_back();
            }

            return false;
        };

        dfs(dfs, "JFK");
        return res;
    }
};
