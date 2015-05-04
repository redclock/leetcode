/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepthNum;
    void dealTreeNode(TreeNode* root, int depth) {
        if (!root) return;
        depth++;
        if (depth > maxDepthNum) maxDepthNum = depth;
        dealTreeNode(root->left, depth);
        dealTreeNode(root->right, depth);
    }

    int maxDepth(TreeNode *root) {
        maxDepthNum = 0;
        dealTreeNode(root, 0);
        return maxDepthNum;        
    }
};