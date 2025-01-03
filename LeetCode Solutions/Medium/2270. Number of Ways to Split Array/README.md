# Ways to Split Array into Subarrays

## Problem Description

You are given a 0-indexed integer array `nums` of length `n`. `nums` contains a valid split at index i if the following are true:

The sum of the first `i + 1` elements is **greater than or equal** to the sum of the last `n - i - 1` elements.
There is at least one element to the right of i. That is, `0 <= i < n - 1`.
Return the number of valid splits in nums.

### Example:
```text
Input: nums = [10, 4, -8, 7]
Output: 2
Explanation:
- Split at index 0: Left = [10], Right = [4, -8, 7]. Left sum = 10, Right sum = 3. Valid.
- Split at index 1: Left = [10, 4], Right = [-8, 7]. Left sum = 14, Right sum = -1. Valid.
- Split at index 2: Left = [10, 4, -8], Right = [7]. Left sum = 6, Right sum = 7. Invalid.
```

## Approach
To solve the problem efficiently, we can use the **prefix sum** technique.

### Key Observations:
1. **Total Sum:**
   The total sum of the array can be used to calculate the right subarray sum dynamically.

2. **Prefix Sum:**
   By maintaining a running sum (`leftSum`) during a single traversal, we can efficiently calculate the left subarray sum and derive the right subarray sum as:
   
   ```
   rightSum = totalSum - leftSum
   ```

3. **Split Condition:**
   A valid split occurs when:
   
   ```
   leftSum >= rightSum
   ```

### Algorithm:
1. Compute the total sum of the array.
2. Traverse the array while maintaining a running sum for the left subarray.
3. Dynamically compute the right subarray sum during traversal.
4. Check if the condition `leftSum >= rightSum` holds for each potential split point.

### Complexity Analysis
- **Time Complexity:**
  - Calculating `totalSum`: \(O(n)\)
  - Traversing the array: \(O(n)\)
  - **Total:** \(O(n)\)

- **Space Complexity:**
  - Constant extra space is used for variables (`totalSum`, `leftSum`, `rightSum`, `count`).
  - **Total:** \(O(1)\)

## Explanation of Example:
For `nums = [10, 4, -8, 7]`:
1. **Total Sum:**
   ```
   totalSum = 10 + 4 + (-8) + 7 = 13
   ```

2. **Traverse Array:**
   - **i = 0:**
     ```
     leftSum = 10, rightSum = 13 - 10 = 3, leftSum >= rightSum (valid)
     ```
   - **i = 1:**
     ```
     leftSum = 10 + 4 = 14, rightSum = 13 - 14 = -1, leftSum >= rightSum (valid)
     ```
   - **i = 2:**
     ```
     leftSum = 14 + (-8) = 6, rightSum = 13 - 6 = 7, leftSum < rightSum (invalid)
     ```

3. **Result:**
   ```
   Count of valid splits = 2
   ```

## Summary
This approach efficiently calculates the number of valid splits using the prefix sum technique. By avoiding nested loops, the solution achieves optimal performance, making it suitable for large input sizes.
