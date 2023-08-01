class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int curr , vector<int> adj[] ,  vector<int>& vis , vector<int>& ans){
        vis[curr] = true;
        ans.push_back(curr);
        for(int val : adj[curr]){
            if(!vis[val]){
                dfs(val , adj , vis , ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(V , false);
        dfs(0 , adj , vis ,ans);
        return ans;
        
    }
};