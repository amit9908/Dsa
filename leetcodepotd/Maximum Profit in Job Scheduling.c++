class Solution {
public:
    int n;

    int getNextIndex(vector<vector<int>>& arr, int l, int currJobEndTime) {
        int r = n - 1;
        int res = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid][0] >= currJobEndTime) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }

    int solve(vector<vector<int>>& arr, int index , vector<int>& dp) {
        if (index >= n)
            return 0;
        if(dp[index] != -1) return dp[index];

        int next = getNextIndex(arr, index + 1, arr[index][1]);
        int taken = arr[index][2] + (next != -1 ? solve(arr, next ,dp) : 0);
        int notTaken = solve(arr, index + 1 ,dp);

        return dp[index] = max(taken, notTaken);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        vector<vector<int>> arr(n, vector<int>(3, 0));

        for (int i = 0; i < n; i++) {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        sort(arr.begin(), arr.end());
        vector<int>dp(n ,-1);
        return solve(arr, 0 , dp);
    }
};