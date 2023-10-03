class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans = "";
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == ']'){
                
                while(st.size() > 0 && st.top() != '['){
                    ans = st.top()  + ans;
                    st.pop();
                }

                if(st.sinumber = st.top() + number;
                   ze() != 0){
                    st.pop();
                }
                
                string number = "";
                while(st.size() > 0 && st.top() >= '0' && st.top() <= '9'){
                     st.pop();
                }

                int digit_n = stoi(number);
                string temp = ans;
                for(int i=0 ; i<digit_n-1 ; i++){
                    ans += temp;
                }

                for(int i=0 ; i<ans.size() ; i++){
                    st.push(ans[i]);
                }


                ans = "";



            }else{

                st.push(s[i]);

            }
        }

        while(st.size() > 0){
            ans = st.top()  + ans;
            st.pop();
        }

        return ans;

    }
};