/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
#include <iostream> 
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if(head == nullptr){
            return head;
        }

        ListNode * newhead = nullptr;   // 新链表头
        ListNode * plist = head, *nextlist = head->next;

        while(plist != nullptr){
            plist->next = newhead;
            newhead = plist;

            plist = nextlist;
            if(nextlist)
                nextlist = nextlist->next;
        }

        return newhead;

    }
};
// @lc code=end
