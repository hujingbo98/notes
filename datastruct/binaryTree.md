<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-12-16
-->

# 二叉树

## 概述

二叉树 (Binary Tree) 是由 n (n >= 0) 个数据元素组成的有限集合，该集合或者为空，或者有一个称为根 (root) 的元素及两个不相交的，被分别称为左子树和右子树的二叉树组成。

二叉树的特点：

* 每个节点最多有两个子节点，且互不相交。

* 左节点和右节点是有顺序的，次序不能颠倒。

满二叉树：所有分支节点都存在左子树和右子树，并且所有叶子结点都在同一层上的二叉树称为满二叉树。

满二叉树的特点：1. 叶子结点只能出现在最下一层。2. 分支节点的度一定是 2。3. 在同样深度的二叉树中，满二叉树的节点个数最多，叶子结点个数最多。

完全二叉树：一颗有 n 个节点的二叉树，对树中的节点按从上至下、从左至右的顺序编号，任意编号为 i (0 <= i <= n) 的节点与满二叉树编号为 i 的节点在二叉树中的位置相同，则这颗二叉树称为完全二叉树。

完全二叉树的特点：1. 叶子结点只能出现在最下两层。2. 最下层的叶子只能集中在左部的连续位置。3. 倒数第二层若有叶子节点，则一定集中在右部的连续位置。4. 如果节点的度为 1，则该节点只有左孩子。5. 同样节点数的二叉树，完全二叉树的深度最小。

## TODO：二叉树的性质

性质 1：二叉树的第 i 层上至多有 2^(i-1) 个节点。

性质 2：深度为 h 的二叉树中至多有 2^h - 1 个节点。

性质 3：

性质 4：

性质 5：

性质 3 证明：

性质 4 证明：

性质 5 证明：

## 遍历

### 先序遍历

[Leetcode 144.二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)

### 中序遍历

[Leetcode 94.二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

### 后续遍历

[Leetcode 145. 二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/)

### 层序遍历

[Leetcode 102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

### 从先序与中序遍历恢复二叉树

[Leetcode 105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

### 从中序与后续遍历恢复二叉树

[Leetcode 106. 从中序与后序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)