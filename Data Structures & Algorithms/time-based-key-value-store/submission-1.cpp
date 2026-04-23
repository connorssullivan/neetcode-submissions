#include <string>
#include <vector>
#include <unordered_map>

 // 1 2 3 4 6 7 8
class TimeMap {
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> store;

public:
    TimeMap() {
        
    }
    
    void set(std::string key, std::string value, int timestamp) {
        store[key].push_back({value, timestamp});
    }
    
    std::string get(std::string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end())
            return "";

        const auto& vec = it->second;
        if (vec.empty())
            return "";

        int left = 0;
        int right = vec.size() - 1;

        int closest = -1;

        while (left <= right)
        {
            int mid = left + ((right-left)/2);

            if (vec[mid].second <= timestamp)
            {
                closest = mid;
                left = mid + 1;
            }

            else
                right = mid - 1;

        }

        return (closest == -1) ? "" : vec[closest].first;
    }
};
