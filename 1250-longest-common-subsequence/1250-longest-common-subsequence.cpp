class Solution {
public:
    int solveUsingRec(string a, string b, int i, int j) {
        //base case
        if(i >= a.length()) {
            return 0;
        }
        if(j >= b.length()) {
            return 0;
        }
        int ans = 0;
        if(a[i] == b[j]) {
            ans = 1 + solveUsingRec(a,b,i+1,j+1);
        }
        else {
            ans = max(solveUsingRec(a,b,i+1,j),solveUsingRec(a,b,i,j+1));
        }
        return ans;
    }

    int solveUsingMem(string &a, string &b, int i, int j,vector<vector<int>> &dp) {
        //base case
        if(i >= a.length()) {
            return 0;
        }
        if(j >= b.length()) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if(a[i] == b[j]) {
            ans = 1 + solveUsingMem(a,b,i+1,j+1,dp);
        }
        else {
            ans = max(solveUsingMem(a,b,i+1,j,dp),solveUsingMem(a,b,i,j+1,dp));
        }
        dp[i][j] =  ans;
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        vector<vector<int>>dp(text1.size()+1, vector<int>(text2.size()+1,-1));
        int ans = solveUsingMem(text1,text2,i,j,dp);
        return ans;
    }
};