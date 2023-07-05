 
 set<int> uniqueElements; //creating
 if (uniqueElements.count(x[j]) > 0)//if found skip
            {
                continue;
            }

uniqueElements.insert(x[j]);

// for(auto str:wordDict){ traversing 
    st.insert(str);
}


 unordered_set<string> st(wordList.begin() , wordList.end());
        st.erase(beginWord);

 if(st.find(currString) != st.end())       