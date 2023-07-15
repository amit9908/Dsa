class Solution {
public:
    bool cycleDetected(int node,vector<bool>&visited, vector<bool>&dfsVisited,vector<vector<int>>& adj){
        visited[node]=true;
        dfsVisited[node]=true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
               bool x= cycleDetected(neighbour,visited,dfsVisited,adj);
               if(x){
                   return true;
                }
            }
            else if(dfsVisited[neighbour]){
                return true;
            }
        }
        dfsVisited[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool>visited(V);
        vector<bool>dfsVisited(V);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool cycleFound=cycleDetected(i,visited,dfsVisited,graph);
                
            }
        }
        vector<int> safeNodes;

        for(int i=0 ; i<V ; i++){
            if(dfsVisited[i] == false){
                safeNodes.push_back(i);
            }
        }  
        return safeNodes;
    }
};