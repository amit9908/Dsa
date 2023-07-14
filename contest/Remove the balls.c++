class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<int> st;
        for(int i=0 ; i<N ; i++){
            if(st.size()){
                int index = st.top();
                if(color[index]==color[i] && radius[index]==radius[i])st.pop();
                else st.push(i);
            }else st.push(i);
        }
        return st.size();
    }
};