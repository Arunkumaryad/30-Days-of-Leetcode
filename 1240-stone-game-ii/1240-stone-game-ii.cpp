class Solution {
public:
    int solveUsingRec(vector<int>& piles, int i, int m, int alice) {
        if(i == piles.size()) {
            return 0;
        }
        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;
        for(int x= 1; x <= 2*m; x++) {
            if(i+x-1 >= piles.size()) 
                 break;
            total += piles[i+x-1];
            if(alice) {
                ans = max(ans,total + solveUsingRec(piles,i+x,max(x,m), !alice));
            }
            else {
                ans = min(ans,solveUsingRec(piles,i+x,max(x,m), !alice));
            }
        }
        return ans;
    }


   int solveUsingMem(vector<int>& piles, int i, int m, int alice, vector<vector<vector<int>>> &dp) {
        if(i == piles.size()) {
            return 0;
        }
        if(dp[i][m][alice] != -1) {
            return dp[i][m][alice] ;
        }
        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;
        for(int x= 1; x <= 2*m; x++) {
            if(i+x-1 >= piles.size()) 
                 break;
            total += piles[i+x-1];
            if(alice) {
                ans = max(ans,total + solveUsingMem(piles,i+x,max(x,m), !alice,dp));
            }
            else {
                ans = min(ans,solveUsingMem(piles,i+x,max(x,m), !alice,dp));
            }
        }
        dp[i][m][alice] = ans;
        return dp[i][m][alice] ;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> dp(piles.size() + 1, vector<vector<int>>(piles.size() + 1, vector<int>(2, -1)));
        int ans = solveUsingMem(piles,0,1,true,dp);
        return ans;
    }
};