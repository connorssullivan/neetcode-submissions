class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> brackets {};

        for (char c : s)
        {
            if (c == '{' || c == '[' || c == '(')
                brackets.push(c);
            
            if (c == ')' )
            {
                if (brackets.empty())
                    return false;

                char top_stack {brackets.top()};
                brackets.pop();
                if (top_stack != '(')
                    return false;
                continue;
            }

            if (c == '}' )
            {
                if (brackets.empty())
                    return false;
                char top_stack {brackets.top()};
                brackets.pop();
                if (top_stack != '{')
                    return false;
                continue;
            }

            if (c == ']' )
            {
                if (brackets.empty())
                    return false;
                char top_stack {brackets.top()};
                brackets.pop();
                if (top_stack != '[')
                    return false;
                continue;
            }
                
        }
        return brackets.empty();
    }
};
