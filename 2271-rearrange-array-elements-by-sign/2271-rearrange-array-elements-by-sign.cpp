class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int posIndx = 0;
        int negIndx = 1;
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            if(nums[i] > 0) {
                ans[posIndx] = nums[i];
                posIndx += 2;
            }
            else {
                ans[negIndx] = nums[i];
                negIndx += 2;
            }
        }
        return ans;
    }
};