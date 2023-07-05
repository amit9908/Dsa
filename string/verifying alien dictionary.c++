class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char , int> mp;
        for(int i=0 ; i<order.size() ; i++){
            mp[order[i]] = i;
        }

        for(int i=0; i<words.size()-1; i++){
            string a = words[i];
            string b = words[i+1];

             int n = min(a.size() , b.size());
             for(int i=0 ; i<n ; i++){
                if(mp[a[i]]  <  mp[b[i]]){
                    break;
                }
                if(mp[a[i]]  >  mp[b[i]]){
                    return false;
                }
                if(i == n-1 && a.size() > b.size()){
                    return false;
                }
             }
        }

        return true;
    }
};