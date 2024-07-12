class Solution {
public:
    int solve(string& s, string r, int x) {
        int i = 0;
        int n = s.size();
        int ans = 0;
        for(int j=0;j<n;j++) {
            s[i++] = s[j];
            if(i > 1 && s[i-2] == r[0] && s[i-1] == r[1]) {
                i = i-2;
                ans += x;
            }
        }
        s.resize(i);
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        string a = "ab";
        string b = "ba";
        if(x < y) {
            swap(a,b);
            swap(x,y);
        }
        return solve(s,a,x) + solve(s,b,y);
    }
};