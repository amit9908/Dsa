

class Solution {
public:
    string res = "";
    vector<string> dis;

    bool isValid(unordered_map<char, int>& map) {
        int ans = 0; // calculating word 
        for (const std::string& s : dis) {
            int digit = 0;
            for (int j = 0; j < s.length(); j++) {
                char key = s[s.length() - 1 - j];
                digit += map.at(key) * pow(10, j);
            }
            ans += digit;
        }

        int res1 = 0; // calculating result 
        for (int i = 0; i < res.length();) {
            char key = res[res.length() - 1 - i];
            res1 += map.at(key) * pow(10, i);
            i++;
        }

        return res1 == ans;
    }

    bool recursionBacktrack(int n, vector<bool>& visited, string& str, unordered_map<char, int>& map) {
        if (n == str.length()) {
            return isValid(map);
        }

        char ch = str[n];

        for (int i = 0; i < 10; i++) {
            if (!visited[i]) {
                visited[i] = true;
                map[ch] = i;
                if(recursionBacktrack(n + 1, visited, str, map))
                    return true;
                map[ch] = 0;
                visited[i] = false;
            }
        }

        return false;
    }
    
    bool isSolvable(vector<string>& words, string& result) {
        dis = words;
        res = result;
        unordered_map<char, int> map;
        string str = "";
        vector<bool> visited(10, false);

        for (const std::string& st : words) {
            for (char ch : st) {
                map[ch] = 0;
            }
        }

        for (char ch : result) {
            map[ch] = 0;
        }

        for (const auto& entry : map) {
            str += entry.first;
        }

        return recursionBacktrack(0, visited, str, map);
    }
};
