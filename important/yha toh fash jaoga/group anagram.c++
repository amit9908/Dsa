class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
       vector<vector<string>> ans;
       map<string , vector<string>> m;
       for(auto str : strs){
           string s = str;
           sort(s.begin() , s.end());
           m[s].push_back(str);
       }

       for(auto it=m.begin() ; it!=m.end() ; it++){
           ans.push_back(it->second);
        }

       return ans;
        
    }
};


class Solution {
public:
    
    std::array<int , 256>hash(string s){
    std::array<int , 256>hash={0};
    for(int i=0 ; i<s.size() ; i++){
        hash[s[i]]++;
    }
    return hash;
   }


    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> ans;
       map<std::array<int,256> , vector<string>> m;
       for(auto str : strs){
        m[hash(str)].push_back(str);
       }

       for(auto it=m.begin() ; it!=m.end() ; it++){
           ans.push_back(it->second);
       }

       return ans;
        
    }
};