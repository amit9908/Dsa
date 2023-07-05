class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        vector<int> ans;
        unordered_map<int , bool> visited;
        
        q.push(0);
        visited[0] = 1;
        ans.push_back(0);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto neighbour : adj[front]){
                if(!visited[neighbour]){
                    ans.push_back(neighbour);
                    q.push(neighbour);
                    visited[neighbour] = 1;
                }
            }
        }
        return ans;
    }
};