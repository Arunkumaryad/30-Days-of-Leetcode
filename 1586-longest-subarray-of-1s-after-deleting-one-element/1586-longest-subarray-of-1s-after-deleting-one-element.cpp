class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int zeroCnt = 0;
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] == 0) {
                zeroCnt++;
            }
            while(zeroCnt > 1) {
                if(nums[left] == 0) {
                    zeroCnt--;
                }
                left++;
            }
            ans = max(ans,i-left);
        }
        return ans;
    }
};