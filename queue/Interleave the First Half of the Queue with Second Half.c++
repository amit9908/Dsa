class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int> q2;
        vector<int> ans;
        int n = q.size();
        int k = n/2;
        int count = 0;
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            q2.push(temp);
            count++;
            
            if(count == k)break;
        }
        
        while(!q.empty() && !q2.empty()){
            int first = q2.front();
            q2.pop();
            
            ans.push_back(first);
            
            
            int second = q.front();
            q.pop();
            
            ans.push_back(second);
        }
        
        if(n&1){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};