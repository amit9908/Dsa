class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        for(int i=0 ; i<n ; i++){
            st.push(i);
        }
        
        while(st.size() != 1){
            int a = st.top() ; st.pop();
            int b = st.top() ; st.pop();
            
            if(M[a][b] == 1){
                st.push(b);
            }else{
                st.push(a);
            }
        }
        
        for(int i=0 ; i<M[0].size() ; i++){
            if(M[st.top()][i] != 0){
                return -1;
            }
        }
        
        for(int i=0 ; i<n ; i++){
            if(M[i][st.top()] == 0 && i != st.top()){
                return -1;
            }
        }
        return st.top();
        
    }
};
