const int INF = INT_MAX;

class Solution {

private:

    vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        queue<pair<int, int>> frontier;

        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                if (grid[i][j] == 0)
                    frontier.push({i,j});
            }
        }

        int distance {};
        int curr_fron_size = frontier.size();

        while (!frontier.empty())
        {
            auto& p = frontier.front();
            frontier.pop();

            curr_fron_size--;

            for (auto& d : dirs)
            {
                pair<int, int> new_coord(p.first + d.first, p.second + d.second); 
                if (new_coord.first > -1 && new_coord.first < ROWS && new_coord.second > -1 && new_coord.second < COLS && grid[new_coord.first][new_coord.second] == INF)
                {
                    frontier.push(new_coord);
                    grid[new_coord.first][new_coord.second] = distance+1;
                }
            }

            if (curr_fron_size == 0)
            {
                distance++;
                curr_fron_size = frontier.size();
            }
        }

        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                if (grid[i][j] == INF)
                    grid[i][j] = -1;
            }
        }

    }
};
