/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// @lc code=start
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        in_queue.push(x);
    }
    
    int pop() {
        while(in_queue.size()>1){
            temp_queue.push(in_queue.front());
            in_queue.pop();
        }
        int retnum = in_queue.front();
        in_queue.pop();
        in_queue.swap(temp_queue);
        return retnum;
    }
    
    int top() {
        while(in_queue.size()>1){
            temp_queue.push(in_queue.front());
            in_queue.pop();
        }
        int retnum = in_queue.front();
        in_queue.pop();
        temp_queue.push(retnum);
        in_queue.swap(temp_queue);
        return retnum;
    }
    
    bool empty() {
        return in_queue.empty();
    }

private:
    queue<int> in_queue;
    queue<int> temp_queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

