#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string solve(string input) {
    string temp;
    for (char ch : input) {
        if (isupper(ch)) {
            temp += tolower(ch);
        } else {
            temp += toupper(ch);
        }
    }
    return temp;
}

int main() {
    string input;
    std::getline(std::cin, input);
    string ans;
    ans = solve(input);

    int i = 0, j = 1;
    while (j < input.size()) {
        char ch = input[j];
        if (isupper(ch)) {
            cout << ans.substr(i, j - i) << endl;
            i = j;
        }
        j++;
    }
    cout << ans.substr(i) << endl;

    return 0;
}

