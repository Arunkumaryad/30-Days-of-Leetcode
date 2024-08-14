class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n-1;i++) {
            int curr = nums[i]+i;
            maxi = max(maxi,curr);
            if(maxi <= i) {
                return false;
            }
        }
        return true;
    }
};