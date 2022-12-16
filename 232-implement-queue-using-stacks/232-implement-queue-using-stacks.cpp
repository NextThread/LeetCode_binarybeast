class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s;
    stack<int> temp;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!s.empty())
        {
            temp.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!s.empty())
        {
            int x=s.top();
            s.pop();
            return x;
        }
        return -1;
    }
    
    /** Get the front element. */
    int peek() {
        return s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};