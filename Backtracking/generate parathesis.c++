class Solution {
public:

    void solve(string& temp , int cOpen ,int cClose , int rOpen , int rClose , vector<string>& res){
        if(rOpen == 0 && rClose == 0){
            res.push_back(temp);
            return;
        }

        if(rOpen > 0){
            temp.push_back('(');
            solve(temp , cOpen+1 , cClose , rOpen-1 , rClose ,res);
            temp.pop_back();
        }

        if(rClose > 0 && cOpen > cClose){
            temp.push_back(')');
            solve(temp , cOpen , cClose+1 ,rOpen , rClose-1 ,res);
            temp.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string temp = "(";
        int currOpen = 1;
        int currClose = 0;
        int remOpen = n-1;
        int remClose = n;
        vector<string> result;
        solve(temp , currOpen , currClose , remOpen , remClose , result);
        return result;
    }
};