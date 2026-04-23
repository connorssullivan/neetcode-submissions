class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<int>> dirs = { {1,0}, {-1,0}, {0,1}, {0,-1} };
        int num_islands {};

        auto dfs = [&] (auto& self, int row, int col) {
            if (row < 0 || row == ROWS || col < 0 || col == COLS || grid[row][col] == '0')
                return;
            
            grid[row][col] = '0';
            for (auto& d : dirs)
            {
                self(self, d[0]+row, d[1]+col);
            }
        };

        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                
                if (grid[i][j] == '1')
                {
                    num_islands++;
                    dfs(dfs, i, j);
                }
            }
        }

        return num_islands;
    }
};
