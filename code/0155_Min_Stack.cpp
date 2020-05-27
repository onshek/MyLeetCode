class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stack_elem, stack_min;
    
    MinStack() {
        stack_min.push(INT_MAX);
    }
    
    void push(int x) {
        stack_elem.push(x);
        if (x < stack_min.top()) {
            stack_min.push(x);
        } else {
            stack_min.push(stack_min.top());
        }
    }
    
    void pop() {
        stack_elem.pop();
        stack_min.pop();
    }
    
    int top() {
        return stack_elem.top();
    }
    
    int getMin() {
        return stack_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */