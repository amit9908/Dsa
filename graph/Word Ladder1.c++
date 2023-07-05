class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string , int>> q;
        q.push({beginWord , 1});
        unordered_set<string> st(wordList.begin() , wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            auto fNode = q.front();
            q.pop();

            string currString = fNode.first;
            int currCount = fNode.second;

            if(currString == endWord) return currCount;

            for(int i=0 ; i<currString.size() ; i++){
                char orginalChar = currString[i];
                for(char ch='a'; ch<='z' ; ch++){
                     currString[i] = ch;
                     if(st.find(currString) != st.end()){
                         q.push({currString , currCount+1});
                         st.erase(currString);
                     }
                }
                currString[i] = orginalChar;
            }
        }
        
        return 0;
    }
};


// In the worst case, we need to visit every word in the wordList, so the overall time complexity can be approximated as O(N * M^2), where N is the number of words in the wordList and M is the average length of the words.