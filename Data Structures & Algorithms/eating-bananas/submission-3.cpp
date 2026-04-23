class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left {1};

        int right = *max_element(piles.begin(), piles.end());
        int k = right;
        while (left <= right)
        {
            int mid = (left + right) / 2;

            int total_hours {};
            for (int pile : piles)
            {
                int hours = (pile + mid - 1) / mid;
                total_hours += hours;
            }

            if (total_hours <= h)
            {
                if (mid < k)
                    k = mid;
                right = mid-1;
            }

            else 
            {
                left = mid + 1;
            }
        }

        return k;
    }
};
