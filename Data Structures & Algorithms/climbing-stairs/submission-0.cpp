class Solution {
public:
    int climbStairs(int n) {
        
        auto fib = [] (auto&& self, int num) {
            if (num == 0 )
                return 0;
            if (num == 1)
                return 1;
            
            return self(self, num-1) +  self(self, num-2);
        };

        int sol = fib(fib, n+1);
        return sol;
    }
};
