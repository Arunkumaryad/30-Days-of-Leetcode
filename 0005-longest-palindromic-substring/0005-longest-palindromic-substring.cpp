class Solution {
public:
    int maxLen = 1;
    int start = 0;
    bool solveUsingRec(string& s, int i, int j) {
        //base case
        if( i >= j) {
            return true;
        }
        bool flag = false;
        if(s[i] == s[j]) {
            flag = solveUsingRec(s,i+1,j-1);
        }
        if(flag) {
            int currLen = j-i+1;
            if(currLen > maxLen) {
                maxLen = currLen;
                start = i;
            }
        }
        return flag;
    }


bool solveUsingMem(string& s, int i, int j, vector<vector<int>>& dp) {
        //base case
        if( i >= j) {
            return true;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        bool flag = false;
        if(s[i] == s[j]) {
            flag = solveUsingMem(s,i+1,j-1,dp);
        }
        if(flag) {
            int currLen = j-i+1;
            if(currLen > maxLen) {
                maxLen = currLen;
                start = i;
            }
        }
        dp[i][j] = flag;
        return dp[i][j];
    }



    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                bool t = solveUsingMem(s,i,j,dp);
            }
        }
        return s.substr(start,maxLen);
    }
};