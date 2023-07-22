class Solution {
public:
    void buildAns(stack<string>& st, string& ans) {
        if (st.empty()) return; // Corrected the base case condition

        string temp = st.top();
        st.pop();
        buildAns(st, ans);
        ans += temp;
    }

    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;
        while (i < path.size()) {
            int s = i;
            int e = i + 1;
            while (e < path.size() && path[e] != '/') {
                e++;
            }
            string minPath = path.substr(s, e - s);
            i = e;
            if (minPath == "/" || minPath == "/.") {
                continue;
            }
            if (minPath != "/..") {
                st.push(minPath);
            } else if (!st.empty()) {
                st.pop();
            }
        }
        string ans;
        buildAns(st, ans); // Initialize ans and call buildAns
        return ans.empty() ? "/" : ans; // Return "/" if ans is empty, otherwise return ans
    }
};