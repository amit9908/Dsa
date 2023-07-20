#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& arr) {
        std::stack<int> st;
        for (int& a : arr) {
            while (!st.empty() && a < 0 && st.top() > 0) {
                int sum = a + st.top();

                if (sum < 0) {
                    st.pop();
                } else if (sum == 0) {
                    st.pop();
                    a = 0;
                    break;
                } else {
                    a = 0;
                    break;
                }
            }

            if (a != 0) {
                st.push(a);
            }
        }

        std::vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // The 'ans' vector needs to be reversed since it was populated in reverse order.
        std::reverse(ans.begin(), ans.end());

        return ans;
    }
};
