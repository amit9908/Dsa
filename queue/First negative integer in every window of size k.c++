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

// C++ implementation to find the first negative
// integer in every window of size k
#include <bits/stdc++.h>
using namespace std;

// function to find the first negative
// integer in every window of size k
void printFirstNegativeInteger(int arr[], int n, int k)
{
	// flag to check whether window contains
	// a negative integer or not
	bool flag;
	
	// Loop for each subarray(window) of size k
	for (int i = 0; i<(n-k+1); i++)		
	{
		flag = false;

		// traverse through the current window
		for (int j = 0; j<k; j++)
		{
			// if a negative integer is found, then
			// it is the first negative integer for
			// current window. Print it, set the flag
			// and break
			if (arr[i+j] < 0)
			{
				cout << arr[i+j] << " ";
				flag = true;
				break;
			}
		}
		
		// if the current window does not
		// contain a negative integer
		if (!flag)
			cout << "0" << " ";
	}
}

// Driver program to test above functions
int main()
{
	int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	printFirstNegativeInteger(arr, n, k);
	return 0;
}
