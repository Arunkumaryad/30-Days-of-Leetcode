class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int one = 0;
        int two = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] == 0) {
                zero++;
            }
            else if(nums[i] == 1) {
                one++;
            }
            else{
                two++;
            }
        }
        int i=0;
        while(zero > 0) {
            nums[i] = 0;
            i++;
            zero--;
        }
        while(one > 0) {
            nums[i] = 1;
            i++;
            one--;
        }
        while(two > 0) {
            nums[i] = 2;
            i++;
            two--;
        }
    }
};