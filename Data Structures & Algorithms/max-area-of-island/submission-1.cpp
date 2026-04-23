class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();


        int biggest_island {};

        auto dfs = [&] (auto&& self, int x, int y, int& curr_size) -> void {
            if (x < 0 || x >= ROWS || y < 0 || y >= COLS)
                return;

            if (grid[x][y] == 1)
            {
                curr_size++;
                biggest_island = max(biggest_island, curr_size);
                grid[x][y] = 0;
                
                self(self, x-1, y, curr_size);
                self(self, x+1, y, curr_size);
                self(self, x, y-1, curr_size);
                self(self, x, y+1, curr_size);
            }
        };

        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                int curr_size = 0;
                dfs(dfs, i, j, curr_size);
            }
        }

        return biggest_island;
    }


};
