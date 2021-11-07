# leetcode-challenge

leetcode解题源代码附注释

## 数据结构

### 剑指 Offer 05. 替换空格

题目要求：请实现一个函数，把字符串 `s` 中的每个空格替换成"%20"。

**示例 1：**

```C++
// 输入：s = "We are happy."
// 输出："We%20are%20happy."
```

#### 解法1-要点

重新定义数组长度：len = len+2*spaceNumber；

**逆序**修改数组内容；（逆序很重要）-（遇到字符，后移，遇到空格替换为%20[修改3个字符]）；

#### 解法1-代码

```C++
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0, len = s.size();
        // 统计空格数量
        for (char c : s) {
            if (c == ' ') count++;
        }
        // 修改 s 长度
        s.resize(len + 2 * count);
        // 倒序遍历修改
        for(int i = len - 1, j = s.size() - 1; i < j; i--, j--) {
            if (s[i] != ' ')
                s[j] = s[i];
            else {
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }
        return s;
    }
};
```

#### 解法2-要点

采用string自带find查找位置。replace根据查找的位置替换为“%20”。

#### 解法2-代码

```C++
class Solution {
public:
    string replaceSpace(string s) {
        int pos = -1;
        while (true)
        {
            // 查找位置。每次查找的起始位置要在之前查找到位置加1
            pos = (int)s.find(' ', ++pos);
            if (pos < 0)
            {
                break;
            }
            // 替换
            s = s.replace(pos,1,"%20"); // 起始位置，替换数量，替换内容
        }

        return s;
    }
};
```

### 剑指 Offer 06. 从尾到头打印链表

#### 剑指 Offer 06.解法1-要点

利用递归，先递推至链表末端；回溯时，依次将节点值加入列表，即可实现链表值的倒序输出。

#### 剑指 Offer 06.解法1-代码

```C++
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        recur(head);
        return res;
    }
private:
    vector<int> res;
    void recur(ListNode* head) {
        if(head == nullptr) return;
        recur(head->next);
        res.push_back(head->val);
    }
};
```

#### 剑指 Offer 06.解法2-要点

链表只能 **从前至后** 访问每个节点，而题目要求 **倒序输出** 各节点值，这种 **先入后出** 的需求可以借助 **栈** 来实现。

#### 剑指 Offer 06.解法2-代码

```C++
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> stk;
        // 顺序入栈
        while(head != nullptr) {
            stk.push(head->val);
            head = head->next;
        }
        vector<int> res;
        // 出栈
        while(!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};
```

#### 剑指 Offer 06.解法3-要点

采用数组存储。获取链表长度，链表顺序访问向数组逆序输入值。

#### 剑指 Offer 06.解法3-代码

```C++
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        int countNode = 0;
        ListNode* Lp = head;
        // 获取长度
        while(Lp!=NULL){
            Lp = Lp->next;
            countNode ++;
        }
        vector_int.resize(countNode);
        Lp = head;
        while(Lp!=NULL){
            vector_int[--countNode]=Lp->val;
            Lp = Lp->next;
        }

        return vector_int;
    }
private:
    vector<int> vector_int;
};
```

### 剑指 Offer 06. 用两个栈实现队列

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

#### 剑指 Offer 06.解法-要点

两个栈，一个栈用来插入，一个栈用来删除。删除时将插入的栈全部元素移动到删除的栈中。

#### 剑指 Offer 06.解法-代码

```C++
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

class CQueue {
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        stack_tail.push(value);
    }

    int deleteHead()
    {
        int temp = 0;
        if (stack_head.empty())
        {
            // 将插入的栈的元素全部插入到推出的栈中
            while (!stack_tail.empty())
            {
                temp = stack_tail.top();
                stack_tail.pop();
                stack_head.push(temp);
            }
        }
        if (stack_head.empty())
        {
            return -1;
        }
        // 出栈 出队列
        temp = stack_head.top();
        stack_head.pop();
        return temp;
    }

private:
    stack<int> stack_head; // 表示推出的栈
    stack<int> stack_tail; // 表示插入的栈
};

```

### 剑指 Offer 20. 表示数值的字符串

**题目**：
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

**数值**（按顺序）可以分成以下几个部分：

1. 若干空格
2. 一个 小数 或者 整数
3. （可选）一个 'e' 或 'E' ，后面跟着一个 整数
4. 若干空格

**小数**（按顺序）可以分成以下几个部分：

1. （可选）一个符号字符（'+' 或 '-'）
2. 下述格式之一：
   1. 至少一位数字，后面跟着一个点 '.'
   2. 至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
   3. 一个点 '.' ，后面跟着至少一位数

**整数**（按顺序）可以分成以下几个部分：

1. （可选）一个符号字符（'+' 或 '-'）

2. 至少一位数字

部分**数值**列举如下：

["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
部分**非数值**列举如下：

["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]

#### 剑指 Offer 20 1解法-代码

采用状态转移图表示各种情况之间的关系。

!["a"](https://pic.leetcode-cn.com/1599283151-YmPMis-Picture1.png)

#### 剑指 Offer 20 解法-代码

```C++
class Solution {
public:
    bool isNumber(string s) {
        /* 状态转移表 */
        typedef pair<char, int> PCI;
        map<char, int> states[]{
            {PCI(' ', 0), PCI('s', 1), PCI('d', 2), PCI('.', 4)}, //  0. start with 'blank'
            {PCI('d', 2), PCI('.', 4)},                           // 1. 'sign' before 'e'
            {PCI('d', 2), PCI('.', 3), PCI('e', 5), PCI(' ', 8)}, // 2. 'digit' before 'dot'
            {PCI('d', 3), PCI('e', 5), PCI(' ', 8)},              // 3. 'digit' after 'dot'
            {PCI('d', 3)},                                        // 4. 'digit' after 'dot' (‘blank’ before 'dot')
            {PCI('s', 6), PCI('d', 7)},                           // 5. 'e'
            {PCI('d', 7)},                                        // 6. 'sign' after 'e'
            {PCI('d', 7), PCI(' ', 8)},                           // 7. 'digit' after 'e'
            {PCI(' ', 8)}};                                       // 8. end with 'blank'

        int p = 0;
        char t;
        for (char c : s)
        {
            if (c >= '0' && c <= '9')
                t = 'd';
            else if (c == '+' || c == '-')
                t = 's';
            else if (c == 'e' || c == 'E')
                t = 'e';
            else if (c == '.' || c == ' ')
                t = c;
            else
                t = '?';
            
            if (states[p].count(t) == 0) // 状态不存在退出
                return false;
            p = states[p][t];    // 状态转移
        }
        return p == 2 || p == 3 || p == 7 || p == 8;
    }
};
```

### 剑指 Offer 24. 反转链表

定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

#### 剑指 Offer 24.解法-要点

使用三个指针。一个存头节点cur，一个存放尾pre（新链表头），tmp一个暂存头节点的后一个。

#### 剑指 Offer 24.解法-代码

```C++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *pre = nullptr;
        while(cur != nullptr) {
            ListNode* tmp = cur->next; // 暂存后继节点 cur.next
            cur->next = pre;           // 修改 next 引用指向
            pre = cur;                 // pre 暂存 cur
            cur = tmp;                 // cur 访问下一节点
        }
        return pre;
    }
};

```
