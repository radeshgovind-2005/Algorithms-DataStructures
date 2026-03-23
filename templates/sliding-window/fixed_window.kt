/**
 * Fixed Sliding Window Template - Kotlin
 * Window size k is constant throughout the traversal.
 *
 * Use when: max/min/sum/average of subarrays of fixed size k.
 * Time: O(n), Space: O(1)
 */

fun fixedWindow(arr: IntArray, k: Int): Int {
    val n = arr.size
    if (n < k) return -1  // or throw, depending on problem

    // Build the initial window
    var windowVal = 0
    for (i in 0 until k) {
        windowVal += arr[i]  // replace with your logic
    }

    var result = windowVal  // track answer (max, min, etc.)

    // Slide: add incoming element, remove outgoing element
    for (right in k until n) {
        val left = right - k
        windowVal += arr[right]   // add new right element
        windowVal -= arr[left]    // remove old left element
        result = maxOf(result, windowVal)  // update answer
    }

    return result
}

fun main() {
    val arr = intArrayOf(2, 1, 5, 1, 3, 2)
    val k = 3
    println(fixedWindow(arr, k))  // 9 (subarray [5,1,3])
}
