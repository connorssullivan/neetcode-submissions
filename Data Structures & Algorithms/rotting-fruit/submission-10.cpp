class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh {};
        int mins {};

        queue<pair<int, int>> rotten;
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                if (grid[i][j] == 2)
                {
                    rotten.push({i,j});
                }

                if (grid[i][j] == 1)
                    fresh++;
            }
        }

        vector<vector<int>> dirs = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        while (fresh > 0 && !rotten.empty())
        {
            int s = rotten.size();
            for (int i {}; i < s; i++)
            {
                auto p = rotten.front();
                rotten.pop();
                
                

                for (auto& d : dirs)
                {
                    if (p.first + d[0] < ROWS && p.first + d[0] >= 0 &&
                        p.second + d[1] < COLS && p.second + d[1] >= 0 &&
                        grid[p.first + d[0]][p.second + d[1]] == 1 
                    )
                    {
                        grid[p.first + d[0]][p.second + d[1]] = 2;
                        rotten.push({p.first + d[0], p.second + d[1]});
                        fresh--;
                    }
                }
            }

            mins++;
        }


        if (fresh == 0)
            return mins;
        return -1;

    }
};
