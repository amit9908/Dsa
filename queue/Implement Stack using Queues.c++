class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0 ; i<q.size()-1 ; i++){
            int front = q.front();
            q.pop();
            q.push(front);

        }
    }
    
    int pop() {
        int top = q.front();
        return top;
    }
    
    int top() {
        retunrn q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};