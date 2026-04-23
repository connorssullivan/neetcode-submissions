class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int, vector<int>, less<int>> occurences;
        unordered_map<char, int> mp;

        for (int t : tasks)
            mp[t]++;
        
        for (auto& [key, val] : mp)
            occurences.push(val);
        
        queue<pair<int, int>> offsets;
        int time {};
        while (!occurences.empty() || !offsets.empty())
        {
            time++;

            if (!occurences.empty())
            {
                int t = occurences.top();
                occurences.pop();

                if (t > 1)
                    offsets.push({t-1, time+n});
            }

            if (!offsets.empty() && offsets.front().second <= time)
            {
                auto val = offsets.front().first;
                offsets.pop();

                occurences.push(val);
            }
        }
        
        return time;
    }
};
