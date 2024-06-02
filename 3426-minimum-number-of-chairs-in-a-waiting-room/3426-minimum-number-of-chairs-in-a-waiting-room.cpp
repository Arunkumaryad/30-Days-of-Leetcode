class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0;
        int cnt = 0;
        int n = s.size();
        for(int i=0;i<n;i++) {
            if(s[i] == 'E') {
                cnt++;
            }
            if(s[i] == 'L') {
                cnt--;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};