class Solution {
public:
    int findSum(vector<int>& nums, int d) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += ceil((double)(nums[i]) / (double)(d));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        //base case
        if(nums.size() > threshold) return -1;
        int start = 1;
        int maxi = INT_MIN;
        for(auto num : nums) {
            maxi = max(maxi,num);
        }
        int end = maxi;
        int mid = start + (end-start) / 2;
        while(start <= end) {
            if(findSum(nums,mid) <= threshold) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
        }
        return start;
    }
};