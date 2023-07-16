class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
        stack<int> s;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            s.push(front);
        }
        
        while(!s.empty()){
            int top = s.top();
            s.pop();
            q.push(top);
        }
        return q;
    }
};