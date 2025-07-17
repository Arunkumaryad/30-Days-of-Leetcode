class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 2;
        for(int i=0;i<k;i++) {
            vector<int> remainderDp(k,0);
            for(auto it : nums) {
                int numMod = it % k;
                int requiredMod = (i-numMod + k) % k;
                remainderDp[numMod] = remainderDp[requiredMod] + 1;
            }
            for(auto dp : remainderDp) {
                ans = max(ans, dp);
            }
        }
        return ans;
    }
};