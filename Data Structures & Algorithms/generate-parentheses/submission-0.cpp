#include <stack>
#include <iostream>
#include <string>
#include <vector>

class Solution {
private:
    void backTrack(int openN, int closeN, int n, std::vector<std::string>& res, std::string& stack){
        if (openN == closeN && openN == n)
        {
            res.push_back(stack);
        }

        if (openN < n)
        {
            stack += '(';
            backTrack(openN + 1, closeN, n, res, stack);
            stack.pop_back();
        }

        if (closeN < openN)
        {
            stack += ')';
            backTrack(openN,closeN + 1, n, res, stack);
            stack.pop_back();
        }
    }
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string s {};
        backTrack(0, 0, n, res, s);

        return res;
    }
};
