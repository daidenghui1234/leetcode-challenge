/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 * 
 * Solution description:
 * 记录进位值
 * 数值等于两数和加上进位 最后除以10
 * 进位等于两数和加上进位 最后对10取余数
 * 
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 建立头指针和位移指针
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2)
        {
            // 如果为空 设置值为0
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;

            if (!head)  // 如果没有头
            {
                head = tail = new ListNode(sum % 10);
            }
            else    // 头指针存在 创建节点位移指针后移
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;   // 计算进位值
            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }

        if (carry > 0)  // 如果进位大于0 加一个节点
        {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
// @lc code=end

// 递归
// class Solution
// {
// public:
//     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
//     {
//         if (l1 == NULL and l2 == NULL) // 都为空返回空
//         {
//             return NULL;
//         }
//         // 其中一个为空返回另一个
//         if (l1 == NULL)
//             return l2;
//         if (l2 == NULL)
//             return l1;

//         int a = l1->val + l2->val;
//         ListNode *p = new ListNode(a % 10);
//         p->next = addTwoNumbers(l1->next, l2->next);
//         if (a >= 10)
//             p->next = addTwoNumbers(p->next, new ListNode(1));
//         return p;
//     }
// };
