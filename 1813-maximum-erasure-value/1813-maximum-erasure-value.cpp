class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        unordered_set<int> st;
        int i = 0;
        int j = 0;
        while(j < n) {
            sum += nums[j];
            while(st.count(nums[j])) {
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            st.insert(nums[j]);
            j++;
            ans = max(ans,sum);
        }
        return ans;
    }
};