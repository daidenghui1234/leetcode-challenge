/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */
#include <stdio.h>
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }

        // 每一个旧链表后插入节点
        OldaddNewNode(head);

        
        // 根据旧表设置新表的随机指针
        NewNodeCopyRand(head);


        Node *newHead = head->next;
        // 将链表的新旧节点分开
        separateNode(head,newHead);

        // printNode(newHead);

        return newHead;
    }

private:
    void OldaddNewNode(Node *head){

        Node *pNode = head, *nextNode = head->next;
        Node *tempNewNode = NULL;

        // 旧表之后加新表
        while(pNode != NULL){
            tempNewNode = new Node(pNode->val);
            pNode->next = tempNewNode;
            tempNewNode->next = nextNode;
            pNode = nextNode;
            if(nextNode) nextNode = nextNode->next;
        }
    }

    void NewNodeCopyRand(Node *head)
    {
        Node* pNode = head;
        while(pNode != NULL){
            if(pNode->random)
                pNode->next->random = pNode->random->next;
            pNode = pNode->next->next;
        }
    }

    void separateNode(Node* head, Node *newHead)
    {
        Node* pNode = head, *pNewNode = newHead;
        while( pNode != NULL){
            pNode->next = pNewNode->next;
            if(pNewNode->next)
                pNewNode->next = pNewNode->next->next;
            pNode = pNode->next;
            pNewNode = pNewNode->next;
        }
    }
    void printNode(Node* head){
        Node* pNode = head;
        while(pNode != NULL){
            cout << pNode->val << " ";
            pNode = pNode->next;
        }
        cout << endl;
    }
};
// @lc code=end

