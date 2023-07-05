int maxIndexDiff(int arr[], int n) {
    vector<int> left(n), right(n);
    left[0] = arr[0];
    right[n - 1] = arr[n - 1];
    
    // Step 1: Fill the 'left' array with minimum values on the left side of each element
    for (int i = 1; i < n; i++) {
        left[i] = min(left[i - 1], arr[i]);
    }
    
    // Step 2: Fill the 'right' array with maximum values on the right side of each element
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], arr[i]);
    }
    
    int i = 0, j = 0, mx = 0;
    
    // Step 3: Find the maximum difference j - i where arr[i] <= arr[j]
    while (j != n) {
        if (left[i] <= right[j]) {
            mx = max(mx, j - i);
            j++;
        } else {
            i++;
        }
    }
    
    return mx;
}
// t.c o(n)
// s.c 0(n)