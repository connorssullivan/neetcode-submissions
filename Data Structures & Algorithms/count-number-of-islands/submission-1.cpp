class Solution {
private:

public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();


        int num_islands {};

        auto dfs = [&] (auto&& self, int x, int y) -> bool {
            if (x < 0 || x >= ROWS || y < 0 || y >= COLS)
                return false;
            
            
            if (grid[x][y] == '1')
            {
                grid[x][y] = 0;
                
                self(self, x+1, y);
                self(self, x-1, y);
                self(self, x, y+1);
                self(self, x, y-1);

                return true;
            }

            return false;
        };

        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                bool isIsland = dfs(dfs, i, j);
                if (isIsland)
                    num_islands++;
            }
        }

        return num_islands;
    }

   
};
