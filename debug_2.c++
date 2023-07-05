#include <iostream>
using namespace std;

int solve(int n, int* dp, int x, int& index) {
    if (n == 0) {
        dp[n] = 0;
        return 0;
    }
    if (n == 1) {
        dp[n] = 1;
        return 1;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    int ans = solve(n - 1, dp, x, index) + solve(n - 2, dp, x, index);
    index++;

    if (ans != x) {
        dp[n] = ans;
    } else {
        return index + 1;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int* dp = new int[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = -1;
    }

    int index = 0;
    int x = solve(n, dp, dp[n], index);

    if (x != -1) {
        cout << "Present at index: " << x << endl;
    } else {
        cout << "Value not found." << endl;
    }

    delete[] dp;
    return 0;
}





