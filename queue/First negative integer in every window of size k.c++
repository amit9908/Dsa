#include <vector>
#include <deque>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> ans;
    deque<long long> q;

    // Iterate through the first K elements and add indices of negative integers to the deque.
    for (int i = 0; i < K; i++) {
        if (A[i] < 0) {
            q.push_back(i);
        }
    }

    // Process the remaining elements from index K to N-1.
    for (int i = K; i < N; i++) {
        // If the deque is empty, there are no negative integers in the window.
        if (q.empty()) {
            ans.push_back(0);
        } else {
            ans.push_back(A[q.front()]);
        }

        // Remove elements that are no longer in the window from the front of the deque.
        while (!q.empty() && (i - q.front() >= K)) {
            q.pop_front();
        }

        // Add the current element index to the deque if it is negative.
        if (A[i] < 0) {
            q.push_back(i);
        }
    }

    // Process the last window of size K separately.
    if (q.empty()) {
        ans.push_back(0);
    } else {
        ans.push_back(A[q.front()]);
    }

    return ans;
}
