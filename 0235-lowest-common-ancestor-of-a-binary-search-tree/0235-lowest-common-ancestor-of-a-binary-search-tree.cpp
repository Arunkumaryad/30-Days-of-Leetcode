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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //Base case.
        if(root == NULL) {
            return NULL;
        }
        //if p and q are present in leftsubtree of root node.
        if(p->val < root->val && q->val < root->val) {
            TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
            return leftAns;
        }
        //if p and q are present in rightsubtree of root node.
        if(p->val > root->val && q->val > root->val) {
            TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
            return rightAns;
        }
        //if p is present in left side and q is present in right side of root.
        if(p->val < root->val && q->val > root->val) {
            return root;
        }
        //if q is present in left side and p is present in right side of root.
        if(q->val < root->val && p->val > root->val) {
            return root;
        }
        return root;
    }
};