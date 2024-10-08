class Solution {
public:
    int solveUsingRec(string &a, string &b, int i, int j) {
        //base case
        if(i == a.length()) {
            return b.length()-j;
        }
        if(j == b.length()) {
            return a.length()-i;
        }
        int ans = 0;
        if(a[i] == b[j]) {
            ans = 0 + solveUsingRec(a,b,i+1,j+1);
        }
        else {
            int insert = 1 + solveUsingRec(a,b,i+1,j+1);
            int replace = 1 + solveUsingRec(a,b,i+1,j);
            int deletion = 1 + solveUsingRec(a,b,i,j+1);
            ans = min(insert, min(replace,deletion));
        }
        return ans;
    }

    int solveUsingMem(string &a, string &b, int i, int j,vector<vector<int>>& dp) {
        //base case
        if(i == a.length()) {
            return b.length()-j;
        }
        if(j == b.length()) {
            return a.length()-i;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if(a[i] == b[j]) {
            ans = 0 + solveUsingMem(a,b,i+1,j+1,dp);
        }
        else {
            int insert = 1 + solveUsingMem(a,b,i+1,j+1,dp);
            int replace = 1 + solveUsingMem(a,b,i+1,j,dp);
            int deletion = 1 + solveUsingMem(a,b,i,j+1,dp);
            ans = min(insert, min(replace,deletion));
        }
        dp[i][j] =  ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length()+1,-1));
        int ans = solveUsingMem(word1,word2,i,j,dp);
        return ans;
    }
};