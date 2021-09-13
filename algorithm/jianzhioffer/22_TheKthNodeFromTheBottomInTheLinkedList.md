<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-13
-->

Problem Source : <https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/>
Solution Source : <https://github.com/hujingbo98/algorithm/blob/master/source/jianzhioffer/22_TheKthNodeFromTheBottomInTheLinkedList.cpp>

剑指 Offer 22、链表中倒数第k个节点

输入一个链表，输出该链表中倒数第 k 个节点。为了符合大多数人的习惯，本题从 1 开
始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有 6 个节点，从头节点开始，
它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。

示例：

```txt
给定一个链表: 1->2->3->4->5, 和 k = 2.
返回链表 4->5.
```

方法一：双指针-快慢指针

快慢指针的思想。将第一个指针 r 指向链表的第 k 个节点，第二个指针 l 指向链表的头结点。此时，指针 l 恰好是从指针 r 开始的倒数第 k 个节点。此时两个指针同步向后走，当第一个指针 r 走到最后一个节点的时，指针 l 恰好指向链表的倒数第k 个节点。

时间复杂度为 O(n)，其中 n 为链表的节点个数。
空间复杂度为 O(1)。

```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getKthFromEnd(ListNode* head, int k) {
    if (!head) return nullptr;
    ListNode *l = head, *r = head;
    while (--k) {
        r = r->next;
    }
    while (r->next) {
        l = l->next;
        r = r->next;
    }
    return l;
}
```
