class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        
        std::vector<int> sol;

        std::vector<int> pref;
        std::deque<int> post;

        int temp { nums[0] };
        pref.push_back(temp);
        for (int i=1; i < nums.size(); i++) 
        {
            temp *= nums[i];
            pref.push_back(temp);
        }

        /* Check 1
        std::cout << "Pre array [";
        for (int i=0; i < pref.size(); i++) 
        {
            std::cout << pref[i] << ", ";
        }
        std::cout << "]\n";
        */

        
        temp = nums[nums.size()-1];
        post.push_front(temp);
        for (int i = nums.size() - 2; i > -1; i--)
        {
            temp *= nums[i];
            post.push_front(temp);
        }

        /*Check 2
        std::cout << "Post array [";
        for (int i=0; i < post.size(); i++) 
        {
            std::cout << post[i] << ", ";
        }
        std::cout << "]\n";
        */

        for (int i=0; i < nums.size(); i++)
        {
            int left { 1 };
            int right { 1 };

            if (i-1 > -1)
                left = pref[i-1];
            if ( i+1 < nums.size())
                right = post[i+1];
            
            std::cout << left << " *  " << right << " = " << left * right << "\n";
            sol.push_back(left * right);
            
        }

        return sol;
    }
};

