class Solution {
private:
    void bfs(map<pair<int,int> , bool>& vis ,int row,  int col , vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[{row , col}] = true;

        while(!q.empty()){
            auto fnode = q.front();
            q.pop();
            int x = fnode.first;
            int y = fnode.second;

            int dx[] = {-1 , 0 , 1 , 0};
            int dy[] = {0 , 1 , 0 , -1};
            
            for(int i=0 ; i<4 ; i++){
                int newX = x  +  dx[i];
                int newY = y + dy[i];
                if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && !vis[{newX , newY}] && grid[newX][newY] == '1'){
                    q.push({newX , newY});
                    vis[{newX , newY}] = true;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid){
      map<pair<int,int> , bool> vis;
      int count = 0;
      
      for(int row=0 ; row<grid.size() ; row++){
          for(int col=0 ; col<grid[0].size() ; col++){
              if(!vis[{row,col}] && grid[row][col] == '1'){
                  bfs(vis , row ,col ,grid);
                  count++;
              }
          }
      }
      
      return count;
        
    }
};