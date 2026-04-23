class MinStack {
private:
    stack<int> my_stack;
    stack<int> min_stack;
public:
    MinStack() {
    }
    
    void push(int val) {
        my_stack.push(val);
        if (min_stack.empty())
            min_stack.push(val);
        else
        {
            val = min(val, min_stack.top());
            min_stack.push(val);
        }
    }
    
    void pop() {
        my_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return my_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

