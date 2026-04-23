class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1; 
        auto it = std::max_element(piles.begin(), piles.end());
        int right = *it;
        int min_ban {right};

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int curr_hours {};
        
            for (int i {}; i < piles.size(); i++)
            {
                int curr_pile = piles[i];

                curr_hours += (curr_pile + mid -1) / mid;
            }

            if (curr_hours <= h && min_ban > mid)
                min_ban = mid;

            if (curr_hours > h)
                left = mid+1;
            if (curr_hours <= h)
                right = mid-1;
        }

        return min_ban;
    }
};
