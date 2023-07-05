#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s = "aaabauif";
    // Map of Char & Int
    map<char, int> m;
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
    }
    // Check Which One Is Having Frequency == 1
    for (int i = 0; i < s.size(); i++)
    {
        if (m[s[i]] == 1){
        cout << s[i] << endl;
        break;
        }

    }
    // If we don't find any we just return -1
}
