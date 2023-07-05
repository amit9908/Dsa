class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> arr = grid;
        int count =0;
        int ansTime = 0;

        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j] == 2){
                    auto coordinate = make_pair(i,j);
                    q.push({coordinate , 0});
                }
            }
        }
        
        while(!q.empty()){
            auto fnode = q.front();
            q.pop();
            int x = fnode.first.first;
            int y = fnode.first.second;
            int time = fnode.second;

            int dx[] = {-1 , 0 ,1 , 0};
            int dy[] = {0 , 1 , 0, -1};

            for(int i=0 ; i<4 ; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX>=0 && newX < arr.size() && newY >=0 && newY < arr[0].size() && arr[newX][newY] == 1){
                    pair<int,int> newCord = make_pair(newX , newY);
                    ansTime = max(ansTime , time+1);
                    q.push({newCord , time+1});
                    
                    arr[newX][newY] = 2;
                }
            }
            
        }
        for(int i=0 ; i<arr.size() ; i++){
            for(int j=0 ; j<arr[0].size() ; j++){
                if(arr[i][j] == 1) return -1;
            }
        }
        return ansTime;
        
    }
};