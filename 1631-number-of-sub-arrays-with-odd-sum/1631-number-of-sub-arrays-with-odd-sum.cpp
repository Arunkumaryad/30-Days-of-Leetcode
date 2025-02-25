class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int odd = 0, even = 1, sum = 0, cnt = 0;

        for (int num : arr) {
            sum += num;
            if (sum % 2 == 0) {
                cnt = (cnt + odd) % mod;
                even++;
            } else {
                cnt = (cnt + even) % mod;
                odd++;
            }
        }

        return cnt;
    }
};
