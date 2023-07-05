class Solution {
public:
    bool isAnagram(string s, string t) {
       if(t.length() < s.length()) return false;
       sort(s.begin() ,s.end());
       sort(t.begin() , t.end());
       if(s == t){
           return true;
       }else{
           return false;
       }
    }
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[256] = {0};
        for(int i=0 ; i<s.size() ; i++){
            hash[s[i]]++;
        }

        for(int i=0 ; i<t.size() ; i++){
            hash[t[i]]--;
        }

        for(int i=0 ; i<256 ; i++){
            if(hash[i] != 0){
                return false;
            }
        }
        return true;
    }
};