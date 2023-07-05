class Solution {
public:
    
      int getRemove(string s)
    {
        stack<char> stck;
        int i = 0;
        while(i < s.size())
        {
            if(s[i] == '(')
                stck.push('(');
            else if(s[i] == ')')
            {
                if(stck.size() > 0 && stck.top() == '(')
                    stck.pop();
                else
                    stck.push(')');
            }
            i++;
        }
        return stck.size();
    }

    void solve(string s , int removeCnt ,  vector<string>& ans ,map<string , bool>& m){
        if(m[s] == true) return;
        else m[s] = true;

        if(removeCnt == 0){
            int numRemoval = getRemove(s);
            if(numRemoval == 0){
                ans.push_back(s);
                return;
            }
        }

        for(int i=0 ; i<s.length() ; i++){
            string leftStr = s.substr(0,i);
            string rightStr = s.substr(i+1);

            string temp = leftStr + rightStr;
            solve(temp, removeCnt -1 , ans , m);
        }
    }
     
    vector<string> removeInvalidParentheses(string s) {
        int removeCnt = getRemove(s);

         vector<string> ans;
         map<string , bool> m;

         solve(s , removeCnt , ans , m);
         return ans;
    }
};