class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt=0;

     vector<int>freq(26,0);
        for(auto it:allowed)
        freq[it-'a']++;

        for(auto str:words){
            cnt++;
            for(auto ch:str){
                if(freq[ch-'a'] ==0){
                    cnt--;
                break;
                }
            }
        }

        return cnt;
    }
};