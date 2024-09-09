class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        //first k element ko process karo
        for(int i=0;i<k;i++) {
            int ele = nums[i];
            pq.push(ele);
        }
        //remaining element ko process karo
        for(int i=k;i<n;i++) {
            int ele = nums[i];
            if(pq.top() < ele) {
                pq.pop();
                pq.push(ele);
            }
        }
        int ans = pq.top();
        return ans;
    }
};