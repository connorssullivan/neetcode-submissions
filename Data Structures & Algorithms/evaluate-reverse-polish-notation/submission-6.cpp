#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        stack<int> nums;

        for (int i {}; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();

                int sum = num1 + num2;
                nums.push(sum);
            }

            else if (tokens[i] == "-")
            {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();

                int sum = num1 - num2;
                nums.push(sum);
            }

            else if (tokens[i] == "*")
            {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();

                int product = num1 * num2;
                nums.push(product);
            }

            else if (tokens[i] == "/")
            {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();

            
                int quotion = num1 / num2;
                nums.push(quotion);
            }

            else {
                int num = stoi(tokens[i]);
                nums.push(num);
            }
        }
        return nums.top();
    }
};


