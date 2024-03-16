class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n =  nums.size();
        int target = 0;
        for(int i=0;i<n;i++) {
            int start = i+1;
            int end = n-1;
            while(start < end) {
                int sum = nums[i]+nums[start]+nums[end];
                if(sum == target) {
                    st.insert({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                }
                else if(target > sum) {
                    start++;
                }
                else{
                    end--;
                }
            }
        }
        for(auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};