class Solution {
public:
    bool isValid(string s) {
        stack<char> my_stack;

        for (int i {}; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                my_stack.push(s[i]);
            
            else
            {
                if (my_stack.empty())
                    return false;
                if (my_stack.top() == '(' && s[i] != ')')
                    return false;
                if (my_stack.top() == '[' && s[i] != ']')
                    return false;
                if (my_stack.top() == '{' && s[i] != '}')
                    return false;
                
                my_stack.pop();
            }
        }

        return my_stack.empty();
    }
};
