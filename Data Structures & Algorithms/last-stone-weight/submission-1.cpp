class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> sizes;

        for (const int& i : stones)
            sizes.push(i);

        while (sizes.size() > 1)
        {
            int big_stone = sizes.top();
            sizes.pop();

            int small_stone = sizes.top();
            sizes.pop();

            int new_stone = big_stone - small_stone;

            if (new_stone > 0)
                sizes.push(new_stone);

        }

        if (sizes.size() == 1)
            return sizes.top();

        return 0;
    }
};
