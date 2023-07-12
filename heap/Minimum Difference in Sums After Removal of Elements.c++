class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        long long ans = LONG_LONG_MAX;
        vector<long long> prefix(nums.size(), -1), suffix(nums.size(), -1);

        priority_queue<long long> pq;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            pq.push(nums[i]);

            if (pq.size() > n) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == n) {
                prefix[i] = sum;
            }
        }

        priority_queue<long long, vector<long long>, greater<long long>> pq2;
        sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            sum += nums[i];
            pq2.push(nums[i]);

            if (pq2.size() > n) {
                sum -= pq2.top();
                pq2.pop();
            }

            if (pq2.size() == n) {
                suffix[i] = sum;
            }
        }

        for (int i = n - 1; i < 2 * n; i++) {
            
            ans = min(ans, prefix[i] - suffix[i + 1]);
            
        }

        return ans;
    }
};