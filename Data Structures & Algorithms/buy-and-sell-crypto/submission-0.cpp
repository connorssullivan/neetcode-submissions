#include <vector>
#include <iostream>



class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy_price {prices[0]};
        int max_profit {0};

        for (int i=1; i < prices.size(); i++)
        {
            max_profit = std::max(prices[i] - buy_price, max_profit);

            if (buy_price > prices[i])
                buy_price = prices[i];
            
        }

        return max_profit;

    }
};
