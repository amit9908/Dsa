class Solution {
public:

    bool isConvert(string& a  , string& b){
        if(a.length() != b.length() || a.length() == 0) return false;
        int cnt = 0;
        for(int i=0 ; i<a.length() ; i++){
            if(a[i] != b[i])
             cnt++;
        }

        if(cnt == 1) 
           return true;
        else 
           return false;
    }
    int min(int& a , int b){
        if(a < b)
          return a;
        return b;  
    }
    void solve(string& src , string& des , map<string , bool>& vis ,vector<vector<string>>& res , vector<string>& path  ,vector<string>& dict , int& size){
        if(des.compare(path[path.size()-1]) == 0){
            res.push_back(path);
            size = min(size,path.size());
            
        }

        for(auto word : dict){
            if(isConvert(src,word)){
                if(vis[word] ==  false){
                    path.push_back(word);
                    vis[word] = true;
                    solve(word , des , vis , res , path , dict ,size);
                    path.pop_back();
                    vis[word] = false;
                }
            }
        }

       
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> path;
        vector<vector<string>> result;
        map<string , bool> vis;

        int size = INT_MAX;

        path.push_back(beginWord);
        
        solve(beginWord , endWord , vis , result , path , wordList ,size);

        vector<vector<string>> finalAns;
        for(auto i:result){
            if(i.size() == size){
                finalAns.push_back(i);
            }
        }
        return finalAns;
    }
};