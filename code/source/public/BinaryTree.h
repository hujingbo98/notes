/**
 * Author : Hu Jingbo
 * Date   : 2022-01-11
 */

#ifndef __BinaryTree_H__
#define __BinaryTree_H__

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTree {
public:
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
};
#endif // #ifndef __BinaryTree_H__