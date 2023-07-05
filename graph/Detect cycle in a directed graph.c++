class Solution {
public:
    // Function to detect cycle in a directed graph.
     bool cycleDetected(int node,vector<bool>&visited, vector<bool>&dfsVisited,vector<int> adj[]){
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
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V);
        vector<bool>dfsVisited(V);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool cycleFound=cycleDetected(i,visited,dfsVisited,adj);
                    if(cycleFound){
                        return true;
                    }
                
            }
        }
        return false;
    }

};