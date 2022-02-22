/**
 * Source : https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Author : Hu Jingbo
 * Date   : 2022-01-11
 * 
 * 105. 从前序与中序遍历序列构造二叉树
 * 
 * 给定一棵树的前序遍历 preorder 与中序遍历 inorder。请构造二叉树并返回其根节点。
 * 
 * 示例 1:
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * 
 * 示例 2:
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 * 
 * 提示:
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均无重复元素
 * inorder 均出现在 preorder
 * preorder 保证为二叉树的前序遍历序列
 * inorder 保证为二叉树的中序遍历序列
 */

#include <vector>
#include <map>
#include <queue>

#include "gtest/gtest.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * 方法一：递归
     */
    TreeNode* buildTreeByRecursion(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || preorder.size() != inorder.size())
            return nullptr;
        int n = inorder.size();
        unordered_map<int, int> hashMap;
        hashMap.reserve(n);
        for (int i = 0; i < n; ++i) {
            hashMap[inorder[i]] = i;
        }

        TreeNode* node = new TreeNode(preorder[0]);

        int i = hashMap[preorder[0]];

        if (i != 0) {
            vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + i);
            vector<int> leftInorder(inorder.begin(), inorder.begin() + i - 1);
            node->left = buildTreeByRecursion(leftPreorder, leftInorder);
        }

        if (i != n - 1) {
            vector<int> rightPreorder(preorder.begin() + i + 1, preorder.end() - 1);
            vector<int> rightInorder(inorder.begin() + i + 1, inorder.end() - 1);
            node->right = buildTreeByRecursion(rightPreorder, rightInorder);
        }

        return node;
    }
};

static vector<int> LevelOrderTraversal(TreeNode* root) {
    if (!root)
        return {};

    vector<int> ans;
    queue<TreeNode*> q;
    q.emplace(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            ans.emplace_back(node->val);
            q.emplace(node->left);
            q.emplace(node->right);
        } else {
            ans.emplace_back(-1);
        }
    }
    return ans;
}

TEST(Solution, 0105_ConstructBinaryTreeFromPreorderAndInorderTraversal) {
    Solution s;

    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    vector<int> ans = {3,9,20,-1,-1,15,7};
    TreeNode* res = s.buildTreeByRecursion(preorder, inorder);
    // EXPECT_EQ(ans, LevelOrderTraversal(res));
}