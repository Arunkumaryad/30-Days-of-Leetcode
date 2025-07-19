class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(),folder.end());
        vector<string> ans = {folder[0]};
        for(int i=1;i<n;i++) {
            if(folder[i].substr(0, ans.back().size() + 1) != ans.back() + "/") {
            ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};