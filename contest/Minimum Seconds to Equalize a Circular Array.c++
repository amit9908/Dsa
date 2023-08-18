class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int smallestGap = INT_MAX;
        int n = nums.size();
        unordered_map<int, vector<int>> posi;
        
        for (int i = 0; i < n; i++) {
            posi[nums[i]].push_back(i);
        }
        
        for (auto &[key, pos] : posi) {
            pos.push_back(pos[0] + n);
            
            int maxGap = 0;
            for (int i = 1; i < pos.size(); i++) {
                maxGap = max(maxGap, pos[i] - pos[i - 1]);
            }
            smallestGap = min(smallestGap, maxGap);
        }
        return smallestGap / 2;  // Divide by 2 after the loop
    }
};