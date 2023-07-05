class Solution {
public:
    void solve(int index ,string& digits , string& output , vector<string>& ans , vector<string>& mapping){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        
        int digit = digits[index] - '0';
        string n = mapping[digit];

        for(int i=0 ; i<n.length(); i++){
            output.push_back(n[i]);
            solve(index+1 , digits , output , ans ,mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        vector<string>mapping(10);
       
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";
        string output = "";
        solve(0 , digits ,output, ans , mapping);
        return ans;
    }
};

// t.c 0(4^n)
// s.c o(4^n)