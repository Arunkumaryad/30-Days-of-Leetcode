class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        int oddCnt = 0;
        for(auto ch : s) {
            mp[ch]++;
            if(mp[ch] % 2 == 1) {
                oddCnt++;
            }
            else {
                oddCnt--;
            }
        }
        if(oddCnt > 1) {
            return n-oddCnt+1;
        }
        return n;
    }
};