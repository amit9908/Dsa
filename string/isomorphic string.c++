class Solution {
public:
    bool isIsomorphic(string s, string b) {
        int hash[256] = {0};
        bool isCharMapped[256] = {0};

        for(int i=0 ; i<s.size() ; i++){
            if(hash[s[i]] == 0 && isCharMapped[b[i]] == 0){
                 hash[s[i]] = b[i];
                isCharMapped[b[i]] = true;
            }
        }

        for(int i=0 ; i<s.size() ; i++){
            if(char(hash[s[i]]) != b[i]){
                return false;
            }
        }

      return true;
    }
};