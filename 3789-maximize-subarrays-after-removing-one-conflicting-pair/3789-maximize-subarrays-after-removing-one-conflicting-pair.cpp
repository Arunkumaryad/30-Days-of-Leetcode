class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<long long>> conflicts(n+2);
        for(auto pair : conflictingPairs) {
            int a = pair[0];
            int b = pair[1];
            if(a < b) {
                conflicts[b].push_back(a);
            }
            else {
                conflicts[a].push_back(b);
            }
        }
        int maxLeft = 0;
        int secondMaxLeft = 0;
        vector<long long> gains(n+2, 0);
        long long validsubarray = 0;
        for(int right = 1; right <= n; right++) {
            for(auto left : conflicts[right]) {
                if(left > maxLeft) {
                    secondMaxLeft = maxLeft;
                    maxLeft = left;
                }
                else if (left > secondMaxLeft) {
                    secondMaxLeft = left;
                }
            }
            validsubarray += right - maxLeft;
            gains[maxLeft] += maxLeft - secondMaxLeft;
        }
        long long maxgain = *max_element(gains.begin(),gains.end());
        return validsubarray + maxgain;
    }
};