BFS of graph
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans , vis(V,0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto i : adj[front]){
                if(!vis[i]){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        return ans;
    }
};