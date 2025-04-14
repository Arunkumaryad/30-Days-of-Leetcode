class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for(auto str : s) {
            mp[str]++;
        }
        for(auto str : t) {
            mp[str]--;
        }
        for(auto it : mp) {
            if(it.second != 0) {
                return false;
            }
        }
        return true;
    }
};