class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int sol = right;


        while (left <= right)
        {
            int mid = left + ((right-left)/2);

            int time {};
            for (const int p : piles)
            {
                time += ceil(static_cast<double>(p)/mid);
            }

            if (time <= h)
            {
                sol = mid;
                right = mid-1;
            }
            else
                left = mid +1;
        }

        return sol;

    }
};
