/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        list<TreeNode*> listNode;
        list<int> listDepth;
        listNode.push_back(root);
        listDepth.push_back(1);
        while (true) {
            
            TreeNode* p = listNode.front();
            int depth = listDepth.front() + 1;
            listNode.pop_front();
            listDepth.pop_front();
            if (p->left)
            {
                TreeNode* q = p->left;
                if (!q->left && !q->right) return depth;
                listNode.push_back(q);
                listDepth.push_back(depth);
            }
            if (p->right)
            {
                TreeNode* q = p->right;
                if (!q->left && !q->right) return depth;
                listNode.push_back(q);
                listDepth.push_back(depth);
            }
        }
    }
};