class Solution {
public:
    void solve(int i, int k, vector<int>& num, vector<int>& temp, vector<vector<int>>& ans) {
        if (i >= num.size()) {
            if(temp.size() == k) {
                ans.push_back(temp);
            }
            return;
        }

        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(num[i]);
        solve(i + 1, k, num, temp, ans);
        temp.pop_back();

        solve(i + 1, k, num, temp, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if (k > n) return ans;

        vector<int> num;
        for (int i = 1; i <= n; i++) {
            num.push_back(i);
        }

        vector<int> temp;
        solve(0, k, num, temp, ans);
        return ans;
    }
};