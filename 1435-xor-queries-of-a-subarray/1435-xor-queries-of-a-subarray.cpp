class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n+1,0);
        for(int i=0;i<n;i++) {
            prefixXor[i+1] = prefixXor[i] ^ arr[i];
        }
        vector<int>ans;
        for(auto query : queries) {
            int left = query[0];
            int right = query[1];
            ans.push_back(prefixXor[right+1] ^ prefixXor[left]);
        }
        return ans;
    }
};