class Solution {
public:
    int solveUsingMem(int n, vector<int>& dp) {
        if(n == 0) {
            dp[0] = 0;
            return dp[0];
        }
        if(n == 1 || n == 2) {
            dp[n] = 1;
            return dp[n];
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        dp[n] = solveUsingMem(n-1,dp) + solveUsingMem(n-2,dp) + solveUsingMem(n-3,dp);
        return dp[n];
    }
    int tribonacci(int n) {
        // if(n == 0) {
        //     return 0;
        // }
        // if(n == 1 || n == 2) {
        //     return 1;
        // }
        // int ans = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        // return ans;

        vector<int>dp(n+1,-1);
        int ans = solveUsingMem(n,dp);
        return ans;
    }
};