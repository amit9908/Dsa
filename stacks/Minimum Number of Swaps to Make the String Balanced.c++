class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[')
            {
                st.push('[');
            }
            else
            {
                if(!st.empty())
                  st.pop();
                else st.push(']');

            }
        }

         return st.size()/2;
        
    }
};


#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& arr) {
        std::vector<int> st;
        for (int& a : arr) {
            while (!st.empty() && a < 0 && st.back() > 0) {
                int sum = a + st.back();

                if (sum < 0) {
                    st.pop_back();
                } else if (sum == 0) {
                    st.pop_back();
                    a = 0;
                    break;
                } else {
                    a = 0;
                    break;
                }
            }

            if (a != 0) {
                st.push_back(a);
            }
        }
        return st;
    }
};
