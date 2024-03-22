class Solution {
public:
    int RecMemo(int n,vector<int>&dp) {
        //base case.
        if(n == 0 || n == 1) {
            return n;
        }
        //3. if ans is already exists.
        if(dp[n] != -1) {
            return dp[n];
        }
        //2.store ans return dp array.
        dp[n] = RecMemo(n-1,dp) + RecMemo(n-2,dp);
        return dp[n];
    }
    int solveUsingTabulation (int n) {
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
    int fib(int n) {
        //1.create dp array.
        // vector<int>dp(n+1,-1);
        // int ans = RecMemo(n,dp);
        // return ans;

        int ans = solveUsingTabulation(n);
        return ans;
    }
};