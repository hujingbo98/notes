/**
 * Source : https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 * Author : Hu Jingbo
 * Date   : 2022-01-11
 * 
 * 144. 二叉树的前序遍历
 * 
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 * 
 * 示例 1：
 * 输入：root = [1,null,2,3]
 * 输出：[1,2,3]
 * 
 * 示例 2：
 * 输入：root = []
 * 输出：[]
 * 
 * 示例 3：
 * 输入：root = [1]
 * 输出：[1]
 * 
 * 示例 4：
 * 输入：root = [1,2]
 * 输出：[1,2]
 * 
 * 示例 5：
 * 输入：root = [1,null,2]
 * 输出：[1,2]
 * 
 * 提示：
 * 树中节点数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 * 
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
 */

#include <vector>
#include <stack>

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
    vector<int> preorderTraversal_Recursion(TreeNode* root) {
        vector<int> ans;
        function<void(TreeNode*)> recursion = [&recursion, &ans](
            TreeNode* node) {
            if (!node)
                return;
            ans.emplace_back(node->val);
            recursion(node->left);
            recursion(node->right);
        };
        recursion(root);
        return ans;
    }

    /**
     * 方法二：迭代
     */
    vector<int> preorderTraversal_Iteration(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while (root) {
            while (root) {
                ans.emplace_back(root->val);
                if (root->right)
                    s.emplace(root->right);
                root = root->left;
            }
            if (!s.empty()) {
                root = s.top();
                s.pop();
            }
        }
        return ans;
    }

    /**
     * 方法三：标记法迭代：可以统一前序、中序、后序的写法
     */
    vector<int> preorderTraversal_IterationByMarkMethod(TreeNode* root) {
        if (!root)
            return {};
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node) {
                if (node->right) s.emplace(node->right);
                if (node->left) s.emplace(node->left);
                s.emplace(node);
                s.emplace(nullptr);
            } else {
                node = s.top();
                s.pop();
                ans.emplace_back(node->val);
            }
        }
        return ans;
    }
};

static TreeNode* constructBinaryTreeByVector(vector<int> v) {
    if (v.empty())
        return nullptr;
    int n = v.size();
    vector<TreeNode*> vec(n, nullptr);
    for (int i = 0; i < n; ++i) {
        if (v[i] != -1) {
            vec[i] = new TreeNode(v[i]);
        }
    }
    for (int i = 0; i * 2 + 1 < n; ++i) {
        if (vec[i]) {
            vec[i]->left = vec[i * 2 + 1];
            if (i * 2 + 2 < n)
                vec[i]->right = vec[i * 2 + 2];
        }
    }
    return vec[0];
}

TEST(Solution, 0144_BinaryTreePreorderTraversal) {
    Solution s;

    vector<int> v = {1,-1,2,-1,-1,3};
    TreeNode* root = constructBinaryTreeByVector(v);
    vector<int> ans = {1,2,3};
    EXPECT_EQ(ans, s.preorderTraversal_Recursion(root));
    EXPECT_EQ(ans, s.preorderTraversal_Iteration(root));
    EXPECT_EQ(ans, s.preorderTraversal_IterationByMarkMethod(root));
}