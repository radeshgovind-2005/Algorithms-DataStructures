"""
Dynamic Sliding Window Template - Python
Window size grows/shrinks based on a condition.

Use when: longest/shortest subarray satisfying a constraint.
Time: O(n), Space: O(1) or O(k) depending on aux structure
"""

def dynamic_window(arr: list, target: int) -> int:
    left = 0
    window_val = 0  # running aggregate (sum, count, freq map, etc.)
    result = 0      # track best answer

    for right in range(len(arr)):
        # Expand: include arr[right] into the window
        window_val += arr[right]

        # Shrink: contract from left while constraint is violated
        while window_val > target and left <= right:
            window_val -= arr[left]
            left += 1

        # Window [left..right] is now valid — update answer
        result = max(result, right - left + 1)

    return result


if __name__ == "__main__":
    arr = [2, 1, 5, 2, 3, 2]
    target = 7
    print(dynamic_window(arr, target))  # 4 (subarray [5,2,3,2] sum<=7? No — adjust logic)
    # Demo: longest subarray with sum <= target
