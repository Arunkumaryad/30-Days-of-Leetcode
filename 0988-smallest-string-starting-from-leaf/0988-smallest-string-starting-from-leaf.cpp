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
    string str = "~";
public:
    void solve(TreeNode* root, string s) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            str = min(str,char(root->val+'a') + s);
        }
        solve(root->left,char(root->val+'a')+s);
        solve(root->right,char(root->val+'a')+s);
    }
    string smallestFromLeaf(TreeNode* root) {
        solve(root,"");
        return str;
    }
};