class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> st;
        
        while (head != NULL) {
            ans.push_back(head->val);
            head = head->next;
        }
        
        st.push(0);
        vector<int> anss(ans.size(), 0); // Initialize 'anss' with the same size as 'ans' and all elements as 0
        for (int i = ans.size() - 1; i >= 0; i--) {
            int curr = ans[i];
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }
            if (!st.empty()) {
                anss[i] = st.top();
            }
            st.push(curr);
        }

        return anss;
    }
};


class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> st;
        
        while (head != NULL) {
            ans.push_back(head->val);
            head = head->next;
        }
        
        for(int i=0 ; i<ans.size() ; i++){
            while(!st.empty() && ans[i] > ans[st.top()]){
                int kids = st.top();
                st.pop();
                ans[kids] = ans[i];
            }
            st.push(i);
        }

        while(!st.empty()){
            ans[st.top()] = 0;st.pop();
        }

        ans[ans.size()-1] = 0;
        return ans;
    }
};
