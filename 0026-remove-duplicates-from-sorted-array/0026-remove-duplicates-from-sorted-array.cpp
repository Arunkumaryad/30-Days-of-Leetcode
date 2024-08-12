class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        for(int i=0;i<n-1;i++) {
            if(nums[i] != nums[i+1]) {
                nums[cnt] = nums[i+1];
                cnt++;
            }
        }
        return cnt;
    }
};