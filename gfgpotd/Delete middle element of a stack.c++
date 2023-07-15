class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        if(s.size() == (sizeOfStack+1)/2){
            s.pop();
            return;
        }
        
        int x = s.top();
        s.pop();
        deleteMid(s , sizeOfStack);
        s.push(x);
    }
};