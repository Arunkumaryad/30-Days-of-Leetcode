class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordCount = words.size();
        int wordLength = words[0].size();
        int substringLength = wordCount * wordLength;

        if (s.size() < substringLength) return result;

        // Build the frequency map of words
        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            wordFreq[word]++;
        }

        // Iterate over every possible starting index in s for the window
        for (int i = 0; i < wordLength; ++i) {
            unordered_map<string, int> seenWords;
            int left = i;
            int right = i;
            int count = 0;

            while (right + wordLength <= s.size()) {
                // Get the word at the current right index
                string word = s.substr(right, wordLength);
                right += wordLength;

                // If it's a valid word, process it
                if (wordFreq.find(word) != wordFreq.end()) {
                    seenWords[word]++;
                    count++;

                    // If there are too many of this word, move left pointer
                    while (seenWords[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLength);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLength;
                    }

                    // Check if we have a valid window
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Reset the window
                    seenWords.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};