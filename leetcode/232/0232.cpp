class MyQueue {
private:
    stack<int> s0, s1;
public:
    MyQueue() {

    }
    
    void push(int x) {
        s0.push(x);
    }
    
    int pop() {
        in2out();
        int re = s1.top();
        s1.pop();
        return re;
    }
    
    int peek() {
        in2out();
        return s1.top();
    }
    
    void in2out() {
        if(s1.empty()) {
            while(!s0.empty()) {
                s1.push(s0.top());
                s0.pop();
            }
        }
    }
    bool empty() {
        return s0.empty() && s1.empty();
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
