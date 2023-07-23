class Solution {
public:
    vector<int> prevSmaller(vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n, -1);
        s.push(-1);

        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top() != -1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            // Check if the stack is not empty before accessing the top element.
            if (!s.empty()) {
                ans[i] = s.top();
            }

            s.push(i);
        }

        return ans;
    }

    vector<int> nextSmallerr(vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n, -1);
        s.push(-1);

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() != -1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            // Check if the stack is not empty before accessing the top element.
            if (!s.empty()) {
                ans[i] = s.top();
            }

            s.push(i);
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == -1) ans[i] = n;
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev = prevSmaller(heights, n);
        vector<int> nextSmaller = nextSmallerr(heights, n);

        int area = 0;
        for (int i = 0; i < n; i++) {
            area = max(area, heights[i] * (nextSmaller[i] - prev[i] - 1));
        }

        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        vector<vector<int>> v;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                temp.push_back(matrix[i][j] - '0');
            }
            v.push_back(temp);
        }
        int area = largestRectangleArea(v[0]);
        for (int i = 1; i < n; i++) { // Start from i = 1, not i = 0
            for (int j = 0; j < m; j++) {
                if (v[i][j]) {
                    v[i][j] += v[i - 1][j]; // Fix the update for v[i][j]
                } else {
                    v[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(v[i]));
        }
        return area;
    }
};
