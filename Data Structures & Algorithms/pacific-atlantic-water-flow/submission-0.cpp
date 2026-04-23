class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        vector<vector<int>> sol;
        //vector<vector<bool>> visted (ROWS, vector<bool>(COLS, false));

        vector<vector<bool>> pacific (ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic (ROWS, vector<bool>(COLS, false));

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        auto dfs = [&] (auto&& self, int r, int c, int prev, vector<vector<bool>>& ocean) -> void{
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && !ocean[r][c] && heights[r][c] >= prev)
            {
                ocean[r][c] = true;

                for (int i {}; i < 4; i++)
                {
                    self(self, r+dirs[i][0], c+dirs[i][1], heights[r][c], ocean);
                }
            }
        };

        // Pacific: top row and left column
        for (int c = 0; c < COLS; c++) dfs(dfs, 0, c, 0, pacific);
        for (int r = 0; r < ROWS; r++) dfs(dfs, r, 0, 0, pacific);

        // Atlantic: bottom row and right column
        for (int c = 0; c < COLS; c++) dfs(dfs, ROWS - 1, c, 0, atlantic);
        for (int r = 0; r < ROWS; r++) dfs(dfs, r, COLS - 1, 0, atlantic);

        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                if (pacific[i][j] && atlantic [i][j])
                    sol.push_back({i, j});
            }
        }

        return sol;
    }
};
