<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-24
-->

Problem Source : <https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/>

Solution Source : <https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0430_FlattenAMultilevelDoublyLinkedList.cpp>

## 430、扁平化多级双向链表

多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

给你位于列表第一级的头节点，请你扁平化列表，使所有结点出现在单级双链表中。

示例 1：

```txt
输入：head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
输出：[1,2,3,7,8,11,12,9,10,4,5,6]
```

示例 2：

```txt
输入：head = [1,2,null,3]
输出：[1,3,2]
解释：
输入的多级列表如下图所示：
  1---2---NULL
  |
  3---NULL
```

示例 3：

```txt
输入：head = []
输出：[]
```

如何表示测试用例中的多级链表？

```txt
以示例 1 为例：
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
序列化其中的每一级之后：
[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
为了将每一级都序列化到一起，我们需要每一级中添加值为 null 的元素，以表示没有节点
连接到上一级的上级节点。
[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
合并所有序列化结果，并去除末尾的 null 。
[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
```

提示：

```txt
节点数目不超过 1000
1 <= Node.val <= 10^5
```

## 方法一：栈 + 深度优先搜索迭代版

当我们遍历到某个节点 cur 时，如果它的 child 成员非空，那么我们需要将 child 指向的链表元素进行扁平化，我们可以利用一个栈 s 来保存 cur 的 next，等到 child 处理完成后再弹栈，处理栈顶的元素。具体做法如下：

- 如果 cur 的 child 和 next 都非空，就将 next 增加到 s 中。
- 如果 cur 的 child 非空，就将 child 扁平化到 next。
- 如果 next 为空，s 非空，就将 next 设置为 s 的栈顶元素，然后弹栈。
- 将 cur 设置为 cur 的 next 成员。

时间复杂度是 O(n)，其中 n 是多级链表的结点个数。

空间复杂度是 O(n)。如果给定多级链表需要扁平化的结点个数为 d，那么空间复杂度为O(d)。在最坏情况下，链表中除最坏一个节点的 child 为空，其它节点的 child 都不为空，则需要扁平化的结点个数为 n - 1，因此时间复杂度为 O(n)。

```cpp
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
Node* flatten(Node* head) {
    if (!head)
        return nullptr;
    stack<Node*> s;
    Node* cur = head;
    while (cur->next || cur->child || !s.empty()) {
        if (cur->child) {
            if (cur->next)
                s.push(cur->next);
            cur->next = cur->child;
            cur->child->prev = cur;
            cur->child = nullptr;
        }
        if (!cur->next) {
            cur->next = s.top();
            s.top()->prev = cur;
            s.pop();
        }
        cur = cur->next;
    }
    return head;
}
```
