"""
Fixed Sliding Window Template - Python
Window size k is constant throughout the traversal.

Use when: max/min/sum/average of subarrays of fixed size k.
Time: O(n), Space: O(1)
"""

def fixed_window(arr: list, k: int):
    n = len(arr)
    if n < k:
        return None  # or raise, depending on problem

    # Build the initial window
    window_val = 0
    for i in range(k):
        window_val += arr[i]  # replace with your logic

    result = window_val  # track answer (max, min, etc.)

    # Slide: add incoming element, remove outgoing element
    for right in range(k, n):
        left = right - k
        window_val += arr[right]   # add new right element
        window_val -= arr[left]    # remove old left element
        result = max(result, window_val)  # update answer

    return result


if __name__ == "__main__":
    arr = [2, 1, 5, 1, 3, 2]
    k = 3
    print(fixed_window(arr, k))  # 9 (subarray [5,1,3])
