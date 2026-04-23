class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l {}; int r {1};
        int max_p {};

        while (r < prices.size())
        {
            if (prices[l] < prices[r])
            {
                int profit = prices[r] - prices[l];
                max_p = max(max_p, profit);
            }
            else 
                l = r;
            r++;
        }

        return max_p;
    }
};
