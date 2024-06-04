class Solution {
public:
    int solve(vector<int>& h) {
        int n = h.size();
        int start = 0;
        int end = n-1;
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        int ans = 0;
        while(start < end) {
            leftMax = max(leftMax,h[start]);
            rightMax = max(rightMax,h[end]);
            if(rightMax > leftMax) {
                ans += leftMax-h[start];
                start++;
            }
            else{
                ans += rightMax-h[end];
                end--;
            }
        }
        return ans;
    }
    int trap(vector<int>& h) {
        int ans = solve(h);
        return ans;
    }
};