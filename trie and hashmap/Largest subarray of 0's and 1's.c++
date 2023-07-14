
class Solution {
public:
    int maxLen(int arr[], int N) {
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;

        for (int i = 0; i < N; i++) {
            if (arr[i] == 0) {
                sum += -1;
            } else {
                sum += 1;
            }

            if (mp.find(sum) != mp.end()) {
                int index = mp[sum];
                int len = i - index;
                if (len > ans) {
                    ans = len;
                }
            } else {
                mp[sum] = i;
            }
        }

        return ans;
    }
};