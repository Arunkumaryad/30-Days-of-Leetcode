class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        int n = words.size();
        for(int i=0;i<n;i++) {
            if(words[i].substr(0,pref.size()) == pref){
                cnt++;
            }
        }
        return cnt;
    }
};