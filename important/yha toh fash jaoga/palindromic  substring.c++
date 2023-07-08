class Solution {
public:
//to check if the word passed is a palindrome
//0(n3)
bool ispalindrome(string s)
{
    int n=s.length();
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])
        return false;
    }
    return true;
}
    int countSubstrings(string s) {
        int start=0,end=1,count=0;
//to produce different substrings of the string given
        for(int i=0;i<s.length();i++)
        {
            string str="";
            for(int j=i;j<s.length();j++)
            {
                str+=s[j];
                if(ispalindrome(str)) count++;
            }
        }
        return count;
    }
};

// 0(n2)
class Solution {
public:
    
    int expand(string s , int i , int j){
        int count = 0;
        while(i>=0 && j<s.length() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }

        return count;
    }
    
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0 ; i<s.length() ; i++){
            int oddLength = expand(s , i ,i);
            count += oddLength;

            int evenLength = expand(s , i , i+1);
            count += evenLength;
        }

        return count;
    }
};