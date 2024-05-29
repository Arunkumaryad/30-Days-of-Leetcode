class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int cnt = 0;
        int carry = 0;
        for(int i=n-1;i>0;i--) {
            int num = s[i]-'0';
            if(num + carry == 1) {
                cnt += 2;
                carry = 1;
            }
            else {
                cnt++;
            }
        }
        int ans = cnt + carry;
        return ans;
    }
};