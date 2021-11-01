<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-10-04
-->

Problem Source : <https://leetcode-cn.com/problems/path-sum-iii/>

Solution Source : <https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0437_PathSumIII.cpp>

437、路径总和 III

给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

示例 1：

```txt
输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。
```

示例 2：

```txt
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：3
```

提示:

```txt
二叉树的节点个数的范围是 [0,1000]
-10^9 <= Node.val <= 10^9 
-1000 <= targetSum <= 1000 
```

```c++
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
```

## 方法一：深度优先搜索

这个方法是穷举所有的可能，我们访问每一个节点 node，检测以 node 为起始节点且向下延伸的路径有多少种。我们递归遍历每一个节点的所有可能的路径，然后将这些路径数目加起来即为返回结果。

我们首先定义 rootSum(p, val) 表示以节点 p 为起点向下且满足路径总和为 val 的路径数目。我们对二叉树上每个节点 p 求出 rootSum(p, targetSum)，然后对这些路径数目就和即为答案。

我们对节点 p 求 rootSum(p, targetSum) 时，以当前节点 p 为目标路径的起点递归向下进行搜索。假设当前的节点 p 的值为 val，我们对左子树和右子树进行递归搜索，对节点 p 的左孩子节点 pl 求出 rootSum(pl, targetSum - val)，以及对右孩子节点 pr 求出 rootSum(pr, targetSum - val)。节点 p 的 rootSum(p, targetSum) 即等于 rootSum(pl, targetSum - val) 与 rootSum(pr, targetSum - val) 之和，同时，我们还需要判断一下当前节点 p 的值是否刚好等于 targetSum。

我们采用递归遍历二叉树的每个节点 p，对节点 p 求 rootSum(p, val)，然后对它们求和即为答案。

时间复杂度是 O(n^2)，其中 n 是该二叉树节点的个数。对于每一个节点，求以该节点为起点的路径数目时，需要遍历以该节点为根节点的子树的所有节点，因此求该路径所花费的最大时间为 O(n)。我们需要对每个节点求一次以该节点为起点的路径数目，因此时间复杂度是 O(n^2)。

空间复杂度是 O(n)。递归在栈上使用的空间。

```c++
int pathSum(TreeNode* root, int targetSum) {
    if (!root)
        return 0;

    int ans = 0;
    ans += rootSum(root, targetSum);
    ans += pathSum(root->left, targetSum);
    ans += pathSum(root->right, targetSum);

    return ans;
}

int rootSum(TreeNode* root, int targetSum)
{
    if (!root)
        return 0;
    
    int ret = 0;
    if (root->val == targetSum)
        ++ret;

    ret += rootSum(root->left, targetSum - root->val);
    ret += rootSum(root->right, targetSum - root->val);

    return ret;
}
```

## 方法二：深度优先搜索 + 前缀和

我们使用先序遍历二叉树，记录下根节点 root 到当前节点上除当前节点以外所有节点的前缀和 cur。在已保存的路径前缀和中查找是否存在前缀和等于 cur-targetSum。

注意，在深度优先搜索左右子树遍历完成之后，回到当前层，需要把当前节点添加的前缀和去除，避免回溯之后影响上一层。

时间复杂度是 O(n)，其中 n 是二叉树中的节点的个数。利用前缀和只需遍历一次二叉树。

空间复杂度是 O(n)。

```c++
int dfs(TreeNode* node, long long cur, int targetSum, 
    unordered_map<long long, int>& prefix)
{
    if (!node)
        return 0;
    
    int ret = 0;
    cur += node->val;
    if (prefix.count(cur - targetSum))
        ret = prefix[cur - targetSum];

    ++prefix[cur];
    ret += dfs(node->left, cur, targetSum, prefix);
    ret += dfs(node->right, cur, targetSum, prefix);
    --prefix[cur];

    return ret;
}

int pathSum_V2(TreeNode* root, int targetSum)
{
    unordered_map<long long, int> prefix;
    prefix[0] = 1;
    return dfs(root, 0, targetSum, prefix);
}
```
