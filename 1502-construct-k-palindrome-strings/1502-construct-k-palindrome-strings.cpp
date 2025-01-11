class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if( n < k) return false;
        int totalCnt = 0;
        sort(s.begin(),s.end());
        for(int i=0;i<n; ) {
            char currentEle = s[i];
            int cnt = 0;
            while(i < n && s[i] == currentEle) {
                cnt++;
                i++;
            }
            if(cnt%2 != 0) totalCnt++;
        }
        return totalCnt <= k;
    }
};