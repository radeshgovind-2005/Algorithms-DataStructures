/**
 * Dynamic Sliding Window Template - C++
 * Window size grows/shrinks based on a condition.
 *
 * Use when: longest/shortest subarray satisfying a constraint.
 * Time: O(n), Space: O(1) or O(k) depending on aux structure
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dynamicWindow(const vector<int>& arr, int target) {
    int left = 0;
    int windowVal = 0;  // running aggregate (sum, count, freq map, etc.)
    int result = 0;     // track best answer

    for (int right = 0; right < (int)arr.size(); right++) {
        // Expand: include arr[right] into the window
        windowVal += arr[right];

        // Shrink: contract from left while constraint is violated
        while (windowVal > target && left <= right) {
            windowVal -= arr[left];
            left++;
        }

        // Window [left..right] is now valid — update answer
        result = max(result, right - left + 1);
    }

    return result;
}

int main() {
    vector<int> arr = {2, 1, 5, 2, 3, 2};
    int target = 7;
    cout << dynamicWindow(arr, target) << endl;  // longest subarray with sum <= target
    return 0;
}
