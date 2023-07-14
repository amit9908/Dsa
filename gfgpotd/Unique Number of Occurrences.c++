class Solution {
public:
    bool isFrequencyUnique(int n, int arr[]) {
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        
        unordered_map<int, bool> mi;
        for (auto i : mp) {
            if (mi.find(i.second) != mi.end()) {
                return false;
            } else {
                mi[i.second] = true;
            }
        }
        return true;
    }
};