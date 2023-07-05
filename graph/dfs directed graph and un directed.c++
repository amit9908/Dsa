class Solution {
public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int , bool> visited;
        vector<int> vec;
        dfs(0,adj,visited,vec);
        return vec;
        
    }
    
    void dfs(int s,vector<int> adj[],unordered_map<int , bool>& visited,vector<int> &vec){
        visited[s] = true;
        vec.push_back(s);
        for(auto x : adj[s]){
            if(!visited[x]) dfs(x,adj,visited,vec);
        }
        
        return;
    }
};