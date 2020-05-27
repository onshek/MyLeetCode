class MyStack {
public:
    /** Initialize your data structure here. */
    int size;
    queue<int> elem;

    MyStack() {
        size = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        elem.push(x);
        size++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int _size = size;
        for (int i=0; i<_size-1; i++) {
            //cout << "pop " << i << " " << elem.front() << endl;
            elem.push(elem.front()); elem.pop();
        }
        //cout << "pop this " << elem.front() << endl;
        int result = elem.front(); elem.pop();
        size--;
        return result;
    }
    
    /** Get the top element. */
    int top() {
        int result = pop();
        elem.push(result); size++;
        return result;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (size == 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */