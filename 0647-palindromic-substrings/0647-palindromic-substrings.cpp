class Solution {
public:
    int expand(string s,int i,int j)
    {
        int cnt=0;
        while(i>=0 && j<s.length() && s[i]==s[j])
        {
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int totalCnt=0;
        for(int center=0;center<s.length();center++)
        {
            int oddAns = expand(s,center,center);
            int evenAns = expand(s,center,center+1);
            totalCnt+=oddAns+evenAns;
        }
        return totalCnt;
    }
};