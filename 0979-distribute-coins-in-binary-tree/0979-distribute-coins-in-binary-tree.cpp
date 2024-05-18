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
    int ans = 0;
    int solve(TreeNode* root) {
        //base case
        if(root == NULL) {
            return 0;
        }
        int leftKaAns = solve(root->left);
        int rightKaAns = solve(root->right);
        ans += abs(leftKaAns) + abs(rightKaAns);
        return root->val+leftKaAns+rightKaAns-1;
    }
    int distributeCoins(TreeNode* root) {
        solve(root);
        return ans;
    }
};