class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        for(int i=0;i<n;i++) {
            if(word[i] == ch) {
                reverse(begin(word),begin(word)+i+1);
                break;
            }
        }
        return word;
    }
};