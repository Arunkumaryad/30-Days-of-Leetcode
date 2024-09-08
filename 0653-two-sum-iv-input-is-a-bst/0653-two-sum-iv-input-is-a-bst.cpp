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
    void findInOrder(TreeNode* root, vector<int>& inOrder) {
        //base case
        if(root == NULL) {
            return;
        }
        //left
        findInOrder(root->left,inOrder);
        inOrder.push_back(root->val);
        findInOrder(root->right,inOrder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inOrder;
        findInOrder(root,inOrder);
        int n = inOrder.size();
        int start = 0;
        int end = n-1;
        while(start < end) {
            int sum = inOrder[start] + inOrder[end];
            if(sum == k) {
                return true;
            }
            else if(sum < k) {
                start++;
            }
            else {
                end--;
            }
        }
        return false;
    }
};