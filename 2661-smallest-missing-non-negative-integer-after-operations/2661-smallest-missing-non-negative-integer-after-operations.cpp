class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        int x;
        int ans = 0;
        vector<int> res(value, 0);
        for(int i=0;i<n;i++) {
            x = ((nums[i] % value) + value) % value;
            res[x]++;
        }
        while(res[ans % value]--) {
            ans++;
        }
        return ans;
    }
};