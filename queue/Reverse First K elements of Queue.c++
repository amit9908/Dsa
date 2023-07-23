queue<int> modifyQueue(queue<int> q, int k) {
    
    stack<int>s;
    
    for(int i=0;i<k;i++)
    {
        int store=q.front();
        q.pop();
        s.push(store);
    }
    
    
    while(!s.empty())
    {
        int store=s.top();
        s.pop();
        q.push(store);
    }
    
    int count=q.size()-k;
    
    while(count--)
    {
        int v=q.front();
        q.pop();
        q.push(v);
    }

    return q;
    
}
