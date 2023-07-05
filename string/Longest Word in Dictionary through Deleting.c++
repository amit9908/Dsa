class Solution {
public:
    
    string findLongestWord(string s, vector<string>& dictionary) {
        
        string ans = "";
        for(int i=0 ; i<dictionary.size() ; i++){
            string word = dictionary[i];
            int ii=0 , j=0 ,len=0;
            while(ii < s.size() && j < word.size()){
            if(word[j] == s[ii++]){
             len++;
             j++;
            }
         }  
        if(len == word.size() &&(ans.length() < word.length() || (ans.length() == word.length() && ans > word))) ans = word;
        }
        return ans;
    }
};