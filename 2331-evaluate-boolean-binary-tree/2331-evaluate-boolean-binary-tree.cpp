/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root) {
        //base case
        // if(root->val == 0 || root->val == 1) {
        //     return root->val == 1;
        // }
        if(root->val == 0) {
            return false;
        }
        if(root->val == 1) {
            return true;
        }
        if(root->val == 2) {
            bool leftKaAns = solve(root->left);
            bool rightKaAns = solve(root->right);
            return leftKaAns || rightKaAns;
        }
        else if(root->val == 3) {
            bool leftKaAns = solve(root->left);
            bool rightKaAns = solve(root->right);
            return leftKaAns && rightKaAns;
        }
        return false;
    }
    bool evaluateTree(TreeNode* root) {
        return solve(root);
    }
};