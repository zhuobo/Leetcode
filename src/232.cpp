#include <stack>
using std::stack;

class MyQueue {
private:
    stack<int> stk1;
    stack<int> stk2;
public:
    /** Initialize your data structure here. */
    MyQueue() { /* do nothing */ }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if ( empty() ) return -1;
        while ( !stk1.empty() ) {
            int top = stk1.top();
            stk1.pop();
            stk2.push(top);
        }
        int ret = stk2.top();
        stk2.pop();
        while ( !stk2.empty() ) {
            int top = stk2.top();
            stk2.pop();
            stk1.push(top);
        }
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if ( empty() ) return -1;
        while ( !stk1.empty() ) {
            int top = stk1.top();
            stk1.pop();
            stk2.push(top);
        }
        int ret = stk2.top();
        while ( !stk2.empty() ) {
            int top = stk2.top();
            stk2.pop();
            stk1.push(top);
        }
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty();
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
