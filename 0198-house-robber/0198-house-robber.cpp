class Solution {
public:
    int solveUsingRec(vector<int>& nums, int index) {
        //base case
        int n = nums.size();
        if(index >= n) {
            return 0;
        }
        int ans1 = nums[index] + solveUsingRec(nums,index+2);
        int ans2 = 0 + solveUsingRec(nums,index+1);
        int ans = max(ans1,ans2);
        return ans;
    }

    int solveUsingMem(vector<int>& nums, int index,vector<int>& dp) {
        //base case
        int n = nums.size();
        if(index >= n) {
            return 0;
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        int ans1 = nums[index] + solveUsingMem(nums,index+2,dp);
        int ans2 = 0 + solveUsingMem(nums,index+1,dp);
        dp[index] = max(ans1,ans2);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        vector<int>dp(n+1,-1);
        int ans = solveUsingMem(nums,index,dp);
        return ans;
    }
};