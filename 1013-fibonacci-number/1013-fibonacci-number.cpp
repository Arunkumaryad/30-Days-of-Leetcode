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
    int solveUsingTabulation(int n) {
        vector<int>dp(n+1,-1);
        dp[0] = 0;
        if(n == 0) {
            return dp[0];
        }
        dp[1] = 1;
        for(int i=2;i<=n;i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int solveUsigSpaceOptimization(int n) {
        int prev = 0;
        if(n == 0) {
            return 0;
        }
        int curr = 1;
        if(n == 1) {
            return 1;
        }
        int ans = prev + curr;
        for(int i=2;i<=n;i++) {
            ans = prev + curr;
            prev = curr;
            curr = ans;
        }
        return ans;
    }
    int fib(int n) {
        // vector<int>dp(n+1,-1);
        int ans = solveUsigSpaceOptimization(n);
        return ans;
    }
};