class Solution {
public:
bool isPalindrome(string s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
//    time complexity: O(n)
//    space complexity: O(1)
}

bool validPalindrome(string s) {
//    Given a string s, return true if the s can be palindrome after deleting at most one character from it.


    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
        }
        i++;
        j--;
    }
    return true;
//    time complexity: O(n)
//    space complexity: O(1)


}
};