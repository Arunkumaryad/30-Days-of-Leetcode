class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total = n * (n + 1) / 2;
        int countDiv = n / m;
        int sumDiv = m * countDiv * (countDiv + 1) / 2;
        return total - 2 * sumDiv;
    }
};