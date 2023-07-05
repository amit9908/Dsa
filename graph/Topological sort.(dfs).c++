class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void sortTopo(int src , vector<int> adj[]  , unordered_map<int,bool>& vis , vector<int>& ans){
	    vis[src] = true;
	    
	    for(auto neighbour : adj[src]){
	        if(!vis[neighbour]){
	            sortTopo(neighbour , adj , vis ,ans);
	        }
	    }
	    
	    ans.push_back(src);
	    
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    unordered_map<int,bool> vis;
	    for(int i=0 ; i<V ; i++){
	        if(!vis[i]){
	            sortTopo(i , adj , vis , ans);
	        }
	    }
	    
	    int i=0;
	    int j=ans.size()-1;
	    while( i <= j){
	        swap(ans[i],ans[j]);
	        i++;
	        j--;
	    }
	    return ans;
	}
};