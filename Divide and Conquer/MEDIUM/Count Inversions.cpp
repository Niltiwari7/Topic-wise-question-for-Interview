// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
  public:
    // Function to count inversions in the array.
     long long count = 0;  // To store the inversion count.

    // Function to count inversions during the merge step.
    void countInv(vector<int>& arr, int low, int mid, int high) {
        int l = low;    // Left subarray
        int r = mid + 1;  // Right subarray
        int k = 0;      // Index for temp array
        
        vector<int> temp(high - low + 1);  // Temporary array to store sorted data
        
        while (l <= mid && r <= high) {
            if (arr[l] <= arr[r]) {
                temp[k++] = arr[l];
                l++;
            } else {
                count += (mid - l + 1);  // Number of inversions
                temp[k++] = arr[r];
                r++;
            }
        }

        // Copy remaining elements from the left subarray
        while (l <= mid) {
            temp[k++] = arr[l];
            l++;
        }

        // Copy remaining elements from the right subarray
        while (r <= high) {
            temp[k++] = arr[r];
            r++;
        }

        // Copy the sorted subarray back to the original array
        for (int i = 0; i < k; i++) {
            arr[low + i] = temp[i];
        }
    }

    // Recursive function to apply merge sort and count inversions
    void solve(vector<int>& arr, int low, int high) {
        if (low >= high) return;

        int mid = (low + high) / 2;
        
        solve(arr, low, mid);    // Recursively sort the left subarray
        solve(arr, mid + 1, high);  // Recursively sort the right subarray
        
        countInv(arr, low, mid, high);  // Merge the subarrays and count inversions
    }
    int inversionCount(vector<int>& arr) {
        int n = arr.size();
        solve(arr, 0, n - 1); // Start the recursive merge sort
        return count; // Return the total number of inversions
    }
};


