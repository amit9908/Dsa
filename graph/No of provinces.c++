class Solution {
private:
    void dfs(unordered_map<int,bool>& vis, vector<vector<int>>& isConnected, int src) {
        vis[src] = true;
        int size = isConnected[src].size();
        for(int col = 0; col < size; col++) {
            if(isConnected[src][col] == 1 && !vis[col]) {
                dfs(vis, isConnected, col);
            }
        }
    }    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        unordered_map<int,bool> vis;
        int n = isConnected.size();
        for(int i = 1; i <= n; i++) {
            if(!vis[i-1]) {
                dfs(vis, isConnected, i-1);
                cnt++;
            }
        }
        return cnt;
    }
};