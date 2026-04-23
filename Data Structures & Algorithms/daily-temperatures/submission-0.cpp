#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> days;

        for (int i=0; i < temperatures.size() -1 ; i++)
        {
            bool found_match {false};
            for (int j=i+1; j < temperatures.size(); j++)
            {
                if (temperatures[j] > temperatures[i])
                {
                    days.push_back(j - i);
                    found_match = true;
                    break;
                }

            }
            if (!found_match)
            {
                days.push_back(0);
            }
        }
        days.push_back(0);
        return days;
    }
};
