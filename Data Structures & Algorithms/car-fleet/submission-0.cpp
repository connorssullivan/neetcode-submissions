#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <utility> 

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        
        std::vector<std::pair<int, double>> desPosPairs (position.size());

        for (int i=0; i < position.size(); i++)
        {
            std::pair<int, double> timeToTarget;

            timeToTarget.first = position[i];
            timeToTarget.second = static_cast<double>(target - position[i]) / speed[i];

            desPosPairs[i] = timeToTarget;
        }

        std::sort(desPosPairs.begin(), desPosPairs.end(), 
        [] (const std::pair<int, double>& a, const std::pair<int, double>& b) 
        {
            return a.first > b.first;
        });


        std::stack<std::pair<int, double>> fleets;
        fleets.push(desPosPairs[0]);

        for (int i=1; i < position.size(); i++)
        {
            if (desPosPairs[i].second > fleets.top().second)
            {
                fleets.push(desPosPairs[i]);
            }else 
            {
                continue;
            }
        }

        return fleets.size();

    }
};