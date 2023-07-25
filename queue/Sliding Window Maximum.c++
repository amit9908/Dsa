class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        // Process the first window of size k
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        // Process the rest of the windows
        for (int i = k; i < nums.size(); i++) {
            // Remove elements that are outside the current window
            if (!dq.empty() && i - dq.front() >= k) {
                dq.pop_front();
            }

            // Remove elements that are smaller than the current element
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};