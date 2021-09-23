<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-23
-->

Problem Source : <https://leetcode-cn.com/problems/split-linked-list-in-parts/>
Solution Source : <https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0725_SplitLinkedListInParts.cpp>

## 725、分隔链表

给你一个头结点为 head 的单链表和一个整数 k ，请你设计一个算法将链表分隔为 k 个连续的部分。

每部分的长度应该尽可能的相等：任意两部分的长度差距不能超过 1 。这可能会导致有些部分为 null 。

这 k 个部分应该按照在链表中出现的顺序排列，并且排在前面的部分的长度应该大于或等于排在后面的长度。

返回一个由上述 k 部分组成的数组。

示例 1：

```txt
输入：head = [1,2,3], k = 5
输出：[[1],[2],[3],[],[]]
解释：
第一个元素 output[0] 为 output[0].val = 1 ，output[0].next = null 。
最后一个元素 output[4] 为 null ，但它作为 ListNode 的字符串表示是 [] 。
```

示例 2：

```txt
输入：head = [1,2,3,4,5,6,7,8,9,10], k = 3
输出：[[1,2,3,4],[5,6,7],[8,9,10]]
解释：
输入被分成了几个连续的部分，并且每部分的长度相差不超过 1 。
前面部分的长度大于等于后面部分的长度。
```

提示：

```txt
链表中节点的数目在范围 [0, 1000]
0 <= Node.val <= 1000
1 <= k <= 50
```

## 方法一：拆分链表

题目要求将给定的链表分隔成 k 个连续的部分。由于分隔成的每个部分的长度和原始链表的长度有关，因此需要首先遍历链表，得到链表的长度 n。

记 x = n / k，y = n mod k，我们可以计算出，在分隔的 k 个部分中，前 y 个部分的长度为 x + 1，其余每个部分的长度为 x。

分隔链表时，我们先将头节点保存到 cur，因为答案是 k 个链表的数组，所以我们循环 k 次，对于每次循环，我们必须保证 cur 不为空，然后进行如下操作：

1. 将 cur 作为当前部分的头结点，写入到答案中。
2. 计算当前部分的长度 len。
3. 将 cur 向后移动 len - 1 步，则 cur 为当前部分的尾结点。
4. 当 cur 到达当前部分的尾结点时，需要拆分 cur 和后面的一个节点之间的连接关系，在拆分之前需要存储 cur 的后一个节点 next。
5. 令 cur 的 next 指针指向空，完成 cur 和 next 的拆分。
6. 将 next 赋值给 cur。

时间复杂度是 O(n)，其中 n 是链表的长度。需要遍历链表两次，的到链表的长度和分隔链表。

空间复杂度是 O(1)。

```c++
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode*> ans(k, nullptr);
    int n = 0;
    ListNode* cur = head;
    while (cur) {
        ++n;
        cur = cur->next;
    }
    int x = n / k;
    int y = n % k;
    cur = head;
    for (int i = 0; i < k && cur != nullptr; i++) {
        ans[i] = cur;
        int len = x + (i < y ? 1 : 0);
        for (int j = 0; j < len - 1; ++j) {
            cur = cur->next;
        }
        ListNode *next = cur->next;
        cur->next = nullptr;
        cur = next;
    }
    return ans;
}
```
