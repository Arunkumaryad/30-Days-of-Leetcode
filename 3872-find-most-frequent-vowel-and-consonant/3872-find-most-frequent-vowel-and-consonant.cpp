class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch =='o' || ch == 'u') {
            return true;
        }
        return false;
    }
    int maxFreqSum(string s) {
        int n = s.size();
        int maxVowelCnt = 0;
        int maxConstCnt = 0;
        unordered_map<char, int> mp;
        for(int i=0;i<n;i++) {
            if(isVowel(s[i])) {
                mp[s[i]]++;
                maxVowelCnt = max(maxVowelCnt,mp[s[i]]);
            }
            else {
                mp[s[i]]++;
                maxConstCnt = max(maxConstCnt, mp[s[i]]);
            }
        }
        return maxVowelCnt + maxConstCnt;
    }
};