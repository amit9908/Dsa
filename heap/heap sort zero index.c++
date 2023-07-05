class Solution {
public:
    // Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i) {
        int largest = i;
        int lIndex = 2 * i + 1;
        int rIndex = 2 * i + 2;

        // Check if the left child is larger than the current root.
        if (lIndex < n && arr[lIndex] > arr[largest]) {
            largest = lIndex;
        }

        // Check if the right child is larger than the current root.
        if (rIndex < n && arr[rIndex] > arr[largest]) {
            largest = rIndex;
        }

        // If the largest element is not the current root, swap them and heapify the affected subtree.
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // Function to build a Heap from an array.
    void buildHeap(int arr[], int n) {
        // Start from the last non-leaf node and heapify each node in reverse order.
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n) {
        buildHeap(arr, n);

        // Extract elements from the heap one by one in descending order.
        for (int i = n - 1; i > 0; i--) {
            // Move the current root (maximum element) to the end.
            swap(arr[0], arr[i]);

            // Reduce the heap size and heapify the root element.
            heapify(arr, i, 0);
        }
    }
};

 
// Expected Time Complexity: O(N * Log(N)).
// Expected Auxiliary Space: O(1).


