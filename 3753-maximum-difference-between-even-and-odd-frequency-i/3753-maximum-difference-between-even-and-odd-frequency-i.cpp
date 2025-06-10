class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mp;
        int maxOdd = -1;
        int minEven = INT_MAX;
        for(auto ch : s) {
            mp[ch]++;
        }
        for(auto it : mp) {
            if(it.second % 2 != 0) {
                maxOdd = max(maxOdd, it.second);
            }
            else {
                minEven = min(minEven, it.second);
            }
        }
        if(maxOdd == -1 || minEven == INT_MAX) {
            return -1;
        }
        int ans = maxOdd - minEven;
        return ans;
    }
};