/**
 * Fixed Sliding Window Template - C++
 * Window size k is constant throughout the traversal.
 *
 * Use when: max/min/sum/average of subarrays of fixed size k.
 * Time: O(n), Space: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fixedWindow(const vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;  // or throw, depending on problem

    // Build the initial window
    int windowVal = 0;
    for (int i = 0; i < k; i++) {
        windowVal += arr[i];  // replace with your logic
    }

    int result = windowVal;  // track answer (max, min, etc.)

    // Slide: add incoming element, remove outgoing element
    for (int right = k; right < n; right++) {
        int left = right - k;
        windowVal += arr[right];   // add new right element
        windowVal -= arr[left];    // remove old left element
        result = max(result, windowVal);  // update answer
    }

    return result;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << fixedWindow(arr, k) << endl;  // 9 (subarray [5,1,3])
    return 0;
}
