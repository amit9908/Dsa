class Solution
{
public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        unordered_map<char, int> count;
        for (int i = 0; i < S.size(); i++)
        {
            count[S[i]]++;
        }

         

        for (int i = 0; i < S.size(); i++)
        {
            if(count[S[i]] == 1) 
            {
                return S[i];
            }
        }

        return '$'; 
    }
    
};


class Solution
{
public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       vector<int>freq(26,0);
       for(int i=0;i<S.size();i++)
           freq[S[i]-'a']++;
        for(int i=0;i<S.size();i++)
        {
            if(freq[S[i]-'a']==1)
            return S[i];
        }
        return '$';
    }
    
};