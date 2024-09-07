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
    bool solve(TreeNode* root, int sum, int target) {
        //base case
        if(root == NULL) {
            return false;
        }
        sum += root->val;
        if(root->left == NULL && root->right == NULL) {
            if(sum == target) {
                return true;
            }
            else {
                return false;
            }
        }
        bool leftAns = solve(root->left,sum,target);
        bool rightAns = solve(root->right,sum,target);
        return leftAns || rightAns;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = solve(root,sum,targetSum);
        return ans;
    }
};