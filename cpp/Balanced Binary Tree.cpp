/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root, int& depth) {
        if (!root) {
            depth = 0;
            return true;
        }
        if (!root->left && !root->right) {
            depth = 1;
            return true;
        }
        int depthLeft;
        bool balanceLeft = isBalanced(root->left, depthLeft);
        if (!balanceLeft) return false;
        int depthRight;
        bool balanceRight = isBalanced(root->right, depthRight);
        if (!balanceRight) return false;
        if (depthLeft > depthRight) {
            depth = depthLeft + 1;
            return depthLeft - depthRight <= 1;
        }
        else {
            depth = depthRight + 1;
            return depthRight - depthLeft <= 1;
        }
    }
    bool isBalanced(TreeNode *root) {
        int depth;
        return isBalanced(root, depth);
    }
};