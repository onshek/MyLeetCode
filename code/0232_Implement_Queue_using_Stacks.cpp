class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> elem;
    stack<int> tmp_elem;  // 辅助栈
    int size;

    MyQueue() {
        size = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        elem.push(x);
        size++;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int _size = size;
        for (int i=0; i<_size-1; i++) {
            tmp_elem.push(elem.top()); elem.pop();
        }
        int result = elem.top(); elem.pop();
        size--;
        for (int i=0; i<_size-1; i++) {
            elem.push(tmp_elem.top()); tmp_elem.pop();
        }
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        int _size = size;
        for (int i=0; i<_size-1; i++) {
            tmp_elem.push(elem.top()); elem.pop();
        }
        int result = elem.top(); elem.pop();
        elem.push(result);
        for (int i=0; i<_size-1; i++) {
            elem.push(tmp_elem.top()); tmp_elem.pop();
        }
        return result;    
}
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (size==0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */