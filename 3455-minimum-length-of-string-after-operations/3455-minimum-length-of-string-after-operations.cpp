class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        int ans = 0;
        for(auto it : s) {
            mp[it]++;
        }
        for(auto it : mp) {
            if(it.second == 0) continue;
            if(it.second%2 == 0) ans += 2;
            else ans += 1;
        }
        return ans;
    }
};