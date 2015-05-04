/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> view;
    
    void search(TreeNode* root, int depth) {
        if (!root) return;
        if (depth > view.size())
            view.push_back(root->val);
        search(root->right, depth + 1);
        search(root->left, depth + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        search(root, 1);
        return view;
    }
};