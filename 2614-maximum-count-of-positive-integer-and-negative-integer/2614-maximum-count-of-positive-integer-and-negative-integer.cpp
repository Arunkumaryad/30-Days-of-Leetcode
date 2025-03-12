class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int posCnt = 0;
        int negCnt = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] > 0) {
                posCnt++;
            }
            else if(nums[i] < 0) {
                negCnt++;
            }
        }
        int ans = max(posCnt,negCnt);
        return ans;
    }
};