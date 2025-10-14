class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n+1, 1);
        for(int i=1;i<n;i++) {
            if(nums[i] > nums[i-1]) {
                ans[i+1] += ans[i];
            }
            else {
                ans[i+1] = 1;
            }
        }
        for(int i=k;i<=n-k;i++) {
            if(ans[i] >= k && ans[i+k] >= k) {
                return true;
            }
        }
        return false;
    }
};