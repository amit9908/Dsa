class Solution{
public:
    stack<int> insertAtBottom(stack<int> St,int X){
        stack<int>s;
        while(!St.empty()){
            int ch= St.top();
            s.push(ch);
            St.pop();
            
        }
        
        St.push(X);
        while(!s.empty()){
            int ch= s.top();
            St.push(ch);
            s.pop();
        }
        return St;
 
    }
};