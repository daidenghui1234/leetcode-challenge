/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

// @lc code=start
class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        int_stack.push(val);
        if(min_stack.empty() || min_stack.top() > val){
            min_stack.push(val);
        }else{
            min_stack.push(min_stack.top());
        }
    }
    
    void pop() {
        int_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return int_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }

private:
    stack<int> int_stack;
    stack<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

