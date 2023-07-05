class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> res;
	    unordered_map<int, int> indegree;
	    queue<int> q;
	    
	    for(int i=0 ; i<V ; i++){
	        for(auto nbr : adj[i]){
	            indegree[nbr]++;
	        }
	    }
	    
	    for(int i=0 ; i<V ; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int front = q.front();
	        q.pop();
	        res.push_back(front);
	        
	        for(auto neighbour : adj[front]){
	            indegree[neighbour]--;
	            if(indegree[neighbour] == 0){
	                q.push(neighbour);
	            }
	        }
	    }
	    return res;
	    
	}
};