class Solution {
public: 
    vector<pair<int,int>> direct = {{1,2} , {1,-2} , {-1,2} , {-1,-2} , {2,1} , {2,-1} , {-2,1} , {-2,-1}};
    double solve(int n, int k, int row, int col){
        if(row < 0 || row >= n || col < 0 || col >= n ){
            return 0;
        }
        if( k == 0)return 1;
        
        double ans = 0;
        for(auto& dir : direct){
          
          int new_r = row + dir.first;
          int new_c = col + dir.second;

          ans += (double)solve(n , k-1 , new_r , new_c); 
        }
        return (double)ans/(8.0);
    } 
    
    double knightProbability(int n, int k, int row, int col) {
        return solve(n , k , row , col);
    }
};



class Solution {
public: 
    unordered_map<string , double> mp;
    vector<pair<int,int>> direct = {{1,2} , {1,-2} , {-1,2} , {-1,-2} , {2,1} , {2,-1} , {-2,1} , {-2,-1}};
    double solve(int n, int k, int row, int col){
        if(row < 0 || row >= n || col < 0 || col >= n ){
            return 0;
        }
        if( k == 0)return 1;
        
        string key  = to_string(k)+"_"+to_string(row)+"_"+to_string(col);
        
        if(mp.find(key) != mp.end()){
            return mp[key];
        }
        double ans = 0;
        for(auto& dir : direct){
          
          int new_r = row + dir.first;
          int new_c = col + dir.second;

          ans += (double)solve(n , k-1 , new_r , new_c); 
        }
        return mp[key] = (double)ans/(8.0);
    } 
    
    double knightProbability(int n, int k, int row, int col) {
        return solve(n , k , row , col);
    }
};