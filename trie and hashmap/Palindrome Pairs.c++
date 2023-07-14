#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPalindromic(string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        int n = words.size();
        if (n < 2) {
            return ans;
        }
        unordered_map<string, int> m;

        for (int i = 0; i < n; i++) {
            auto s = words[i];
            reverse(s.begin(), s.end());
            m[s] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= words[i].size(); j++) {
                string st1 = words[i].substr(0, j);
                string st2 = words[i].substr(j);

                if (m.count(st1) && isPalindromic(st2) && m[st1] != i) {
                    ans.push_back({ i, m[st1] });
                }

                if (!st1.empty() && m.count(st2) && isPalindromic(st1) && m[st2] != i) {
                    ans.push_back({ m[st2], i });
                }
            }
        }
        return ans;
    }
};