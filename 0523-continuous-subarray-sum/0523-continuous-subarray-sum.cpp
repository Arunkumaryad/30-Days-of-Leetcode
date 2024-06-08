class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2) 
           return false;
        unordered_map<int,int>mp;
        mp[0] = -1;
        int cnt = 0;
        for(int i=0;i<n;i++) {
            cnt += nums[i];
            if(k != 0) {
                cnt = cnt%k;
            }
            if(mp.find(cnt) != mp.end()) {
                if(i-mp[cnt]>1) {
                    return true;
                }
            }
            else{
                mp[cnt] = i;
            }
        }
        return false;
    }
};