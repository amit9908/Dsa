//User function template for C++

class Solution{   
public:
string expandAroundCenter(const string& s, int left, int right) {
    int n = s.length();
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(const string& S) {
    int n = S.length();
    if (n < 2)
        return S;

    string longest = "";

    for (int i = 0; i < n - 1; i++) {
        string odd = expandAroundCenter(S, i, i);
        if (odd.length() > longest.length())
            longest = odd;

        string even = expandAroundCenter(S, i, i + 1);
        if (even.length() > longest.length())
            longest = even;
    }

    return longest;
}

};
