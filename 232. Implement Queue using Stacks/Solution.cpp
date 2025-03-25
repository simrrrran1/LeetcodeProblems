class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.push(x);
    }
    
    int pop() {
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return s1.top();

    }
    
    bool empty() {
        return s1.empty() && s2.empty();
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