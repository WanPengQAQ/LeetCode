//two stack implement a queue
class MyQueue {
    stack<int> input, output;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        // Non...
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        peek();
        int res = output.top();
        output.pop();
        return res;
        
    }
    
    /** Get the front element. */
    int peek() {
        if(!output.empty()){
            return output.top();
        }
        else{//outout.size() == 0 
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            return output.top();

        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }
};
