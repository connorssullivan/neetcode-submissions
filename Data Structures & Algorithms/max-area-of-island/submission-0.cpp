class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int max_area {};

        auto countMaxIslands = [&](auto&& self, int r, int c) {
            if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == 0)
                return 0;
            
            grid[r][c] = 0;
            return 1 + self(self, r+1, c) + self(self, r-1, c) + self(self, r, c+1) + self(self, r, c - 1);  
        };

        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                max_area = max(countMaxIslands(countMaxIslands,i, j), max_area);
            }
        }

        return max_area;
    }
};
