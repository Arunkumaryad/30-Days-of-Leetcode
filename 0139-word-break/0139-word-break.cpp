class Solution {
public:
    bool check(vector<string>& wordDict, string &s) {
        for(auto i : wordDict) {
            if(s == i) {
                return true;
            }
        }
        return false;
    }
    bool solveUsingRec(string &s, vector<string>& wordDict, int start) {
        //base case
        if(start == s.size()) {
            return true;
        }
        string word = "";
        bool flag = false;
        for(int i=start;i<s.size();i++) {
            word += s[i];
            if(check(wordDict,word)) {
                flag = flag || solveUsingRec(s,wordDict,i+1);
            }
        }
        return flag;
    }


bool solveUsingMem(string &s, vector<string>& wordDict, int start,vector<int>& dp) {
        //base case
        if(start == s.size()) {
            return true;
        }
        if(dp[start] != -1) {
            return dp[start];
        }
        string word = "";
        bool flag = false;
        for(int i=start;i<s.size();i++) {
            word += s[i];
            if(check(wordDict,word)) {
                flag = flag || solveUsingMem(s,wordDict,i+1,dp);
            }
        }
        dp[start] = flag;
        return dp[start];
    }

    bool solveUsingTab(string &s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1,true);
        for(int start = s.size()-1;start >= 0;start--) {
            string word = "";
            bool flag = false;
            for(int i=start;i<s.size();i++) {
                word += s[i];
                if(check(wordDict,word)) {
                    flag = flag || dp[i+1];
                }
            }
            dp[start] = flag;
        }
        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        return solveUsingTab(s,wordDict);
    }
};