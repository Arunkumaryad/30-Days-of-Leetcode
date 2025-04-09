class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int ans = -1;
        for(int i=0;i<n;i++) {
            mp[nums[i]]++;
        }
        for(auto it : mp) {
            if(it.second == 1) {
                ans = it.first;
            }
        }
        return ans;
    }
};