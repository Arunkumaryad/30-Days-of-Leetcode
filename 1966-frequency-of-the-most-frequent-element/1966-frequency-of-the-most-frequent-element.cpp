class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int a=0, b=0;
        long long windowSum=0;
        int ans=0;
        while(b<n){
            windowSum+=nums[b];
            while((nums[b]*(b-a+1LL)) - windowSum > k){
                windowSum-=nums[a];
                a++;
            }
            ans= max(ans, b-a+1);
            b++;
        }
        return ans;
    }
};