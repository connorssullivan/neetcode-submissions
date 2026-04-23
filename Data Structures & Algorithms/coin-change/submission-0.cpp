class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int smallest_num_coins = {-1};
        vector<int> curr_coins;

        auto dfs = [&](auto&& self, int index, int total, int num_coins) {
            if ( total > amount || index == coins.size())
                return;
            if (total == amount)
            {
                if (smallest_num_coins == -1 || smallest_num_coins > num_coins)
                    smallest_num_coins = num_coins;
                return;
            }


            self(self, index, total+coins[index], num_coins+1);
            self(self, index+1, total, num_coins);
        };

        dfs(dfs, 0, 0, 0);

        return smallest_num_coins;

    }
};
