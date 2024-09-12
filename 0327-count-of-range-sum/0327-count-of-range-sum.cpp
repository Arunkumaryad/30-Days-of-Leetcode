class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> prefixSums(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }

        return countRangeSum(prefixSums, 0, prefixSums.size() - 1, lower, upper);
    }

private:
    int countRangeSum(vector<long>& prefixSums, int start, int end, int lower, int upper) {
        if (start >= end) return 0;

        int mid = start + (end - start) / 2;
        int count = countRangeSum(prefixSums, start, mid, lower, upper) +
                    countRangeSum(prefixSums, mid + 1, end, lower, upper);

        vector<long> merged;
        int j = mid + 1, k = mid + 1;

        for (int i = start; i <= mid; ++i) {
            while (j <= end && prefixSums[j] - prefixSums[i] < lower) ++j;
            while (k <= end && prefixSums[k] - prefixSums[i] <= upper) ++k;
            count += k - j;
        }

        // Merge the sorted halves
        int left = start, right = mid + 1;
        while (left <= mid && right <= end) {
            if (prefixSums[left] <= prefixSums[right]) {
                merged.push_back(prefixSums[left++]);
            } else {
                merged.push_back(prefixSums[right++]);
            }
        }
        while (left <= mid) merged.push_back(prefixSums[left++]);
        while (right <= end) merged.push_back(prefixSums[right++]);

        for (int i = 0; i < merged.size(); ++i) {
            prefixSums[start + i] = merged[i];
        }

        return count;
    }
};