class Solution {
public:
    bool solveUsingRec(vector<int>& nums, int index, int sum, int target) {
        //base case
        if(index >= nums.size()) {
            return false;
        }
        if(sum > target) {
            return false;
        }
        if(sum == target) {
            return true;
        }
        bool include = solveUsingRec(nums, index+1, sum + nums[index], target);
        bool exclude = solveUsingRec(nums, index+1, sum, target);
        return include || exclude;
    }

     bool solveUsingMem(vector<int>& nums, int index, int sum, int target,vector<vector<int>>& dp) {
        //base case
        if(index >= nums.size()) {
            return false;
        }
        if(sum > target) {
            return false;
        }
        if(sum == target) {
            return true;
        }
        if(dp[index][sum] != -1) {
            return dp[index][sum];
        }
        bool include = solveUsingMem(nums, index+1, sum + nums[index], target, dp);
        bool exclude = solveUsingMem(nums, index+1, sum, target, dp);
        dp[index][sum] =  include || exclude;
        return dp[index][sum];
    }
    bool canPartition(vector<int>& nums) {
        int index = 0;
        int totalSum = 0;
        for(auto it : nums) {
            totalSum += it;
        }
        int currSum = 0;
        if(totalSum & 1) {
            return false;
        }
        int target = totalSum / 2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        bool ans = solveUsingMem(nums,index,currSum,target,dp);
        return ans;
    }
};