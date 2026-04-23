class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> pc(ROWS, vector<bool>(COLS, false));

        auto dfs = [&] (auto&& self, int r, int c, vector<vector<bool>>& seen, int prev) {
            if (r < 0 || r >= ROWS || c < 0 || c >= COLS || seen[r][c] || heights[r][c] < prev)
                return;

            seen[r][c] = true;

            self(self, r+1, c, seen, heights[r][c]);
            self(self, r-1, c, seen, heights[r][c]);
            self(self, r, c+1, seen, heights[r][c]);
            self(self, r, c-1, seen, heights[r][c]);
        };

        for (int i {}; i < ROWS; i++)
        {
            dfs(dfs, i, 0, pc, 0);
            dfs(dfs, i, COLS - 1, atl, 0);
        }

        for (int i {}; i < COLS; i++)
        {
            dfs(dfs, 0, i, pc, 0);
            dfs(dfs, ROWS - 1, i, atl, 0);
        }

        vector<vector<int>> sol;
        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                if (atl[i][j] && pc[i][j])
                {
                    sol.push_back({i, j});
                } 
            }
        }

        return sol;
    }
};
