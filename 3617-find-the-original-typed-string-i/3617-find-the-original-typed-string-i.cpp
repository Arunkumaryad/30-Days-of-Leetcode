class Solution {
public:
    int possibleStringCount(string word) {
        int j = 0;
        int i = 0;
        int sum = 0;
        while(i+1 < word.size()){
            while(word[i] == word[i+1]){
                i++;
            }
            if(i>j){
                sum += i-j;
            }
            j = i;
            i++;
            j++;
        }
        return sum+1;
    }
};