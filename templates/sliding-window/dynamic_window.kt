/**
 * Dynamic Sliding Window Template - Kotlin
 * Window size grows/shrinks based on a condition.
 *
 * Use when: longest/shortest subarray satisfying a constraint.
 * Time: O(n), Space: O(1) or O(k) depending on aux structure
 */

fun dynamicWindow(arr: IntArray, target: Int): Int {
    var left = 0
    var windowVal = 0  // running aggregate (sum, count, freq map, etc.)
    var result = 0     // track best answer

    for (right in arr.indices) {
        // Expand: include arr[right] into the window
        windowVal += arr[right]

        // Shrink: contract from left while constraint is violated
        while (windowVal > target && left <= right) {
            windowVal -= arr[left]
            left++
        }

        // Window [left..right] is now valid — update answer
        result = maxOf(result, right - left + 1)
    }

    return result
}

fun main() {
    val arr = intArrayOf(2, 1, 5, 2, 3, 2)
    val target = 7
    println(dynamicWindow(arr, target))  // longest subarray with sum <= target
}
