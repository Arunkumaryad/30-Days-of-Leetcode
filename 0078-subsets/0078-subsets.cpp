class Solution {
public:
 void solve(vector<int> &output,vector<vector<int>> &ans,int index,vector<int> &nums){
        ans.push_back(output);
        if(index==nums.size()){
            return;
        }
        for(int i = index; i < nums.size(); i++){
            output.push_back(nums[i]);
            solve(output,ans,i+1,nums);
            output.pop_back();
            while(i+1<nums.size() && nums[index] == nums[i+1]){
                i++;
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>>ans;
        vector<int>output;
        int index=0;
        solve(output,ans,0,nums);
        return ans;
    }
};