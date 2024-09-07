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
    int height(TreeNode* root) {
        //base case
        if(root == NULL) {
            return 0;
        }
        int leftKaAns = height(root->left);
        int rightKaAns = height(root->right);
        int ans = max(leftKaAns, rightKaAns) + 1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);
        bool currNode = (diff <= 1);
        bool leftKaAns = isBalanced(root->left);
        bool rightKaAns = isBalanced(root->right);
        if(currNode && leftKaAns && rightKaAns) {
            return true;
        }
        else { 
            return false;
        }
    }
};