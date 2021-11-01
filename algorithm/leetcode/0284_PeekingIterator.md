<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-10-05
-->

Problem Source : <https://leetcode-cn.com/problems/peeking-iterator/>

Solution Source : <https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0284_PeekingIterator.cpp>

## 284、窥探迭代器

请你设计一个迭代器，除了支持 hasNext 和 next 操作外，还支持 peek 操作。

实现 PeekingIterator 类：

PeekingIterator(int[] nums) 使用指定整数数组 nums 初始化迭代器。
int next() 返回数组中的下一个元素，并将指针移动到下个元素处。
bool hasNext() 如果数组中存在下一个元素，返回 true ；否则，返回 false 。
int peek() 返回数组中的下一个元素，但 不 移动指针。

示例：

```txt
输入：
["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
[[[1, 2, 3]], [], [], [], [], []]
输出：
[null, 1, 2, 2, 3, false]
解释：
PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [1,2,3]
peekingIterator.next();    // 返回 1 ，指针移动到下一个元素 [1,2,3]
peekingIterator.peek();    // 返回 2 ，指针未发生移动 [1,2,3]
peekingIterator.next();    // 返回 2 ，指针移动到下一个元素 [1,2,3]
peekingIterator.next();    // 返回 3 ，指针移动到下一个元素 [1,2,3]
peekingIterator.hasNext(); // 返回 False
```

提示：

```txt
1 <= nums.length <= 1000
1 <= nums[i] <= 1000
对 next 和 peek 的调用均有效
next、hasNext 和 peek 最多调用  1000 次
```

进阶：你将如何拓展你的设计？使之变得通用化，从而适应所有的类型，而不只是整数型？

```c++
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
// class Iterator {
//     struct Data;
//     Data* data;
// public:
//     Iterator(const vector<int>& nums);
//     Iterator(const Iterator& iter);
// 
//     // Returns the next element in the iteration.
//     int next();
// 
//     // Returns true if the iteration has more elements.
//     bool hasNext() const;
// };

class PeekingIterator : public Iterator {
public:
    /**
     * 方法一：迭代器
     */
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        mHasNext = Iterator::hasNext();
        if (mHasNext)
            mNextElement = Iterator::next();
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return mNextElement;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int res = mNextElement;
        mHasNext = Iterator::hasNext();
        if (mHasNext) {
            mNextElement = Iterator::next();
        }
        return res;
    }
    
    bool hasNext() const {
        return mHasNext;
    }

    int mNextElement;
    bool mHasNext;
};
```
