class Solution
{
    public:
    //Function to find number of strongly connected components in the graph.
    void topologicalSort(int v , vector<vector<int>>&adj , stack<int>&st,vector<bool>&visited , int i , int parent)
    {
        visited[i] = true;
        for(auto neighbour : adj[i])
        {
            if(!visited[neighbour])
            {
                topologicalSort(v , adj , st , visited , neighbour , i);
            }
        }
        st.push(i);
    }
    
    void dfs(int node , int parent , vector<vector<int>> &adj , vector<bool>&visited)
    {
        visited[node] = true;
        for(auto neighbour  : adj[node])
        {
            if(!visited[neighbour])
            {
                dfs(neighbour , node , adj , visited);
            }
        }
    }
    int kosaraju(int v, vector<vector<int>>& adj)
    {
        vector<bool>visited(v , false);
        stack<int> st;
        for(int i = 0;i<v;i++)
        {
            if(!visited[i])
            {
                topologicalSort(v , adj , st , visited , i , -1);
            }
        }
        
        // Reversing the adjacency list of graph
        vector<vector<int>> revadj(v);
        for(int i = 0;i<v;i++)
        {
            for(auto j : adj[i])
            {
                revadj[j].push_back(i);
            }
        }
        
        int count = 0;
        for(int i = 0;i<v;i++) visited[i] = false;
        while(!st.empty())
        {
            int top = st.top();
            st.pop();
            
            if(!visited[top])
            {
                dfs(top , -1 , revadj , visited);
                count++;
            }
        }
        return count;
    }

};