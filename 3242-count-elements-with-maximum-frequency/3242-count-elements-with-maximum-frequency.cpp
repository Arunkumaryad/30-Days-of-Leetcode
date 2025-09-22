class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        int maxCnt = 0;
        int cnt = 0;
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) {
            mp[nums[i]]++;
            maxCnt = max(maxCnt, mp[nums[i]]);
        }
        for(auto it : mp) {
            if(it.second == maxCnt) {
                cnt += it.second;
            }
        }
        return cnt;
    }
};