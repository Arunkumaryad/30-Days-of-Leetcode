class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = 0;
        int mini = nums[0];
        for(int i=1;i<nums.size();i++) {
            ans = max(ans,nums[i]-mini);
            mini = min(mini,nums[i]);
        }
        if(ans) {
            return ans;
        }
        return -1;
    }
};