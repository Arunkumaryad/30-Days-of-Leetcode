class Solution {
public:
    int solveUsingRec(int n) {
        //base case
        if(n == 0 || n == 1) {
            return n;
        }
        int ans = solveUsingRec(n-1) + solveUsingRec(n-2);
        return ans;
    }

    int solveUsingMem(int n, vector<int>& dp) {
        //base case
        if(n == 0 || n == 1) {
            return n;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        dp[n] = solveUsingMem(n-1,dp) + solveUsingMem(n-2,dp);
        return dp[n];
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        int ans = solveUsingMem(n, dp);
        return ans;
    }
};