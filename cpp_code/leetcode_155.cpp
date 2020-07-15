class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> min_stk;
    MinStack() {
    }
    
    void push(int x) {
        stk.push(x);
        // 添加元素
        // 只需了解当天当前元素后，当前栈的最小值是否有变
        if (min_stk.empty())
            min_stk.push(x);
        else {
            if (x <= min_stk.top()) {
                min_stk.push(x);
            } else {
                min_stk.push(min_stk.top());
            }
        }
        
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
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
