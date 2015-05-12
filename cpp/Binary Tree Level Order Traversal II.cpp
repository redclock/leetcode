/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<int> values;
    vector<int> depths;
    int maxDepth;
    void dealTreeNode(TreeNode* root, int depth) {
        if (!root) return;
        values.push_back(root->val);
        depths.push_back(depth);
        depth++;
        if (depth > maxDepth) maxDepth = depth;
        dealTreeNode(root->left, depth);
        dealTreeNode(root->right, depth);
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        maxDepth = 0;
        dealTreeNode(root, 0);
        vector<vector<int> > result(maxDepth);
        for (int i = 0; i < values.size(); i++){
            result[maxDepth - 1 - depths[i]].push_back(values[i]);
        }
        return result;
    }
};
