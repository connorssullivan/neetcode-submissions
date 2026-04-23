class Solution {
private:
    const int m_directions[4][2]  = { {0,1}, {0, -1}, {1, 0}, {-1, 0} };
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0)
            return 0;

        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        int total_islands {};

        vector<vector<bool>> found(ROWS, vector<bool>(COLS, false));
        
        auto bfs = [&] (int r, int c) {
            queue<pair<int,int>> q;

            q.push({r,c});


            while(!q.empty())
            {
                pair<int, int> temp = q.front();
                q.pop();

                for (int i {}; i < 4; i++)
                {
                    int new_row = temp.first + m_directions[i][0];
                    int new_col = temp.second + m_directions[i][1];

                    if (new_row > -1 && new_col > -1 
                        && new_row < ROWS && new_col < COLS
                        && !found[new_row][new_col] && grid[new_row][new_col] == '1'
                    )
                    {
                        found[new_row][new_col] = true;
                        q.push({new_row, new_col});
                    }
                }
            }

        };

        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                if (grid[i][j] == '1' && !found[i][j])
                {
                    total_islands++;
                    found[i][j] = true;
                    bfs(i, j);
                }
            }
        }

        return total_islands;
    }
};
