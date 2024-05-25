class Solution {
public:
    vector<string> solveUsingRec(string &s, unordered_map<string,bool>& dict, int i) {
        if(i == s.size()) {
            return {""};
        }
        vector<string>ans;
        string word;
        for(int j=i;j<s.size();j++) {
            word.push_back(s[j]);
            if(dict.find(word) == dict.end()) {
                continue;
            }
            auto right = solveUsingRec(s,dict,j+1);
            for(auto eachRightPart : right) {
                string endPart;
                if(eachRightPart.size() > 0) {
                    endPart += " " + eachRightPart;
                }
                ans.push_back(word+endPart);
            }
        }
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>dict;
        for(auto word : wordDict) {
            dict[word] = 1;
        }
        return solveUsingRec(s,dict,0);
    }
};