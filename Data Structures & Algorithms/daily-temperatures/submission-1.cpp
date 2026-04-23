#include <vector>
#include <iostream>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> days (temperatures.size());
        std::stack<int> indexes;

        for (int i=0; i < temperatures.size(); i++)
        {
            if (indexes.empty())
                indexes.push(i);
                
            
            
            else 
            {
                while (!indexes.empty() && temperatures[i] > temperatures[indexes.top()])
                {
                    int days_until_warmer {i - indexes.top()};
                    days[indexes.top()] = days_until_warmer;
                    indexes.pop();
                }

                indexes.push(i);
            }
        }

        while (!indexes.empty())
        {
            int i {indexes.top()};
            days[i] = 0;
            indexes.pop();
        }

        return days;
    }
};

