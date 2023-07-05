class Solution {
public:
    string customSortString(string order, string s) {
        map<char , int>countMap;
        string ans = "";
        for(auto x: s){
            countMap[x]++;
        }
        
        for(auto x : order){
            if(countMap.find(x) != countMap.end()){
                auto temp = countMap.find(x);
                int count = temp->second;
                string s(count , x);
                ans+=s;
                countMap.erase(x);
            }
        }

        for(auto x : countMap){
            string s(x.second , x.first);
            ans+=s;
        }

        return ans;
        
    }
};