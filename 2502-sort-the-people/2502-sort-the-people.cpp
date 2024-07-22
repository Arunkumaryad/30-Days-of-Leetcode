class Solution {
public:
        static vector<string> sortPeople(vector<string>& names, const vector<int>& heights) {
        // find sort permutation
        vector<int> perm(size(names));
        iota(begin(perm), end(perm), 0);
        sort(begin(perm), end(perm), [&](int a, int b) {
            return heights[a] > heights[b];
        });
        // apply sort permutation
        vector<string> ans;
        ans.reserve(size(names));
        transform(begin(perm), end(perm), back_inserter(ans),
                 [&](int a) { return move(names[a]); });
        return ans;
    }
};