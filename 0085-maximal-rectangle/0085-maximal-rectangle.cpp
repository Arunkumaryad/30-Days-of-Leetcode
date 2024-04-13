class Solution {
public:
    vector<int> nextSmallerElement(vector<int> arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);
        for (int i = arr.size() - 1; i >= 0; i--) {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < arr.size(); i++) {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nextSmallerElement(heights);
        for (int i = 0; i < heights.size(); i++) {
            if (next[i] == -1) {
                next[i] = heights.size();
            }
        }
        vector<int> prev = prevSmallerElement(heights);
        vector<int> area(next.size());
        for (int i = 0; i < next.size(); i++) {
            int width = next[i] - prev[i] - 1;
            int len = heights[i];
            int currArea = width * len;
            area[i] = currArea;
        }
        int maxi = INT_MIN;
        for (int i = 0; i < area.size(); i++) {
            maxi = max(maxi, area[i]);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        vector<vector<int>> v(matrix.size(), vector<int>(matrix[0].size(), 0));

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                v[i][j] = matrix[i][j] - '0';
                if (i > 0 && v[i][j]) {
                    v[i][j] += v[i - 1][j];
                }
            }
        }

        int area = largestRectangleArea(v[0]);
        for (int i = 1; i < matrix.size(); i++) {
            area = max(area, largestRectangleArea(v[i]));
        }

        return area;
    }
};