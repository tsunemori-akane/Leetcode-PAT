/*建立一个新栈，栈顶表示原栈里所有值的最小值。每当在原栈里插入一个数字时，若该数字小于等于新栈栈顶，则表示这个数字在原栈里是最小值，我们将其同时插入新栈内。
**每当从原栈里取出一个数字时，若该数字等于新栈栈顶，则表示这个数是原栈里的最小值之一，我们同时取出新栈栈顶的值。
*/
class MinStack {
    stack<int> s, min_s;
public:
    MinStack() {

    }
    
    void push(int x) {
        s.push(x);
        if(min_s.empty() || min_s.top() >= x) {
            min_s.push(x);
        }
    }
    
    void pop() {
        if(min_s.empty() || min_s.top() == s.top()) {
            min_s.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
