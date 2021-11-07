/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

#include <iostream>
#include <stack>
using namespace std;

// @lc code=start
class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        in_stack.push(x);
    }
    
    int pop() {
        if(out_stack.empty())
            remove_in_to_out();
        int retnum = out_stack.top();
        out_stack.pop();
        return retnum;
    }
    
    int peek() {
        if(out_stack.empty())
            remove_in_to_out();
        return out_stack.top();
    }
    
    bool empty() {
        if(out_stack.empty())
            remove_in_to_out();
        return out_stack.empty();
    }

private:
    stack<int> in_stack;    // 输入栈
    stack<int> out_stack;   // 输出栈

    void remove_in_to_out() {
        // 将输入栈中的元素 转移到输出栈
        while(!in_stack.empty()){
            out_stack.push(in_stack.top());
            in_stack.pop();
        }
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
// @lc code=end

