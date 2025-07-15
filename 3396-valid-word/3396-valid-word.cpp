class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) {
            return false;
        }

        bool hasVow = false;
        bool hasCons = false;

        for (char ch : word) {
            if (isalpha(ch)) {
                ch = tolower(ch);

                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    hasVow = true;
                }
                else {
                    hasCons = true;
                }
            }
            else if (!isdigit(ch)) {
                return false;
            }
        }

        return hasVow && hasCons;
    }
};