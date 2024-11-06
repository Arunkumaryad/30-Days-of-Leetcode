class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zeroCnt = 0;
        int oneCnt = 0;
        int twoCnt = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] == 0) {
                zeroCnt++;
            }
            else if(nums[i] == 1) {
                oneCnt++;
            }
            else {
                twoCnt++;
            }
        }
        int i = 0;
        while(zeroCnt) {
            nums[i] = 0;
            zeroCnt--;
            i++;
        }
        while(oneCnt) {
            nums[i] = 1;
            oneCnt--;
            i++;
        }
        while(twoCnt) {
            nums[i] = 2;
            twoCnt--;
            i++;
        }
    }
};