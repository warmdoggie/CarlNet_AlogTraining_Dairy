#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {
        
    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if(stOut.empty()){
            while(!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();
            }
        }

        int x = stOut.top();
        stOut.pop();
        return x;

    }
    int peek() {
        int x = this->pop();
        stOut.push(x);
        return x;
    }
    // int peek() {
        
    //     return stOut.top();
    // }
    
    bool empty() {
        return stOut.empty()&&stIn.empty();
    }
};
