class Solution{
public:

    void insert(stack<int> &St, int key)
    {
        if(St.size() == 0)
        {
            St.push(key);
            return;
        }
        
        int val = St.top();
        
        St.pop();
        
        insert(St, key);
        
        St.push(val);
        
    }
    void Reverse(stack<int> &St)
    {
        
        if(St.size() == 1)
        {
            return;
        }
        
        int key = St.top();
        
        St.pop();
        
        Reverse(St);
        
        insert(St, key);
        
    }
};