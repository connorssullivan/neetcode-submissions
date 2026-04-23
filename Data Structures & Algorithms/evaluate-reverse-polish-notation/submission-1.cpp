#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> numbers;
        int total {};
        //assert(numbers.size() < 3 && "You have an invalid token");

        for (std::string& symbol : tokens)
        {
            if (symbol == "+")
            {
                int num1 {numbers.top()};
                numbers.pop();
                int num2 {numbers.top()};
                numbers.pop();
                numbers.push(num2 + num1);
            }
            else if (symbol == "-")
            {
                int num1 {numbers.top()};
                numbers.pop();
                int num2 {numbers.top()};
                numbers.pop();
                numbers.push(num2 - num1);
            }
            else if (symbol == "*")
            {
                int num1 {numbers.top()};
                numbers.pop();
                int num2 {numbers.top()};
                numbers.pop();
                numbers.push(num1 * num2);
            }
            else if (symbol == "/")
            {
                int num1 {numbers.top()};
                numbers.pop();
                int num2 {numbers.top()};
                numbers.pop();
                numbers.push(num2 / num1);
            }
            else 
            {
                int num = std::stoi(symbol);
                numbers.push(num);
            }
            
        }

        assert(numbers.size() == 1 && "You have an invalid Equation");
        return numbers.top();
        
    }
};


