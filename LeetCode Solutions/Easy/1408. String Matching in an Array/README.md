# String Matching in an Array

## Problem Description
Given an array of strings `words`, return all strings in `words` that are a substring of another string in `words`. You can return the answer in any order.

## Approach 1:

### Overview
The goal is to identify all strings in the input array that are substrings of any other string in the same array. To achieve this, we use a nested loop to compare each string with every other string in the array.

### Steps

1. **Initialize Result Vector**:
   - We start by initializing an empty vector `result` to store the substrings.

2. **Nested Loops**:
   - We use two nested loops to iterate over each pair of strings in the array.
   - The outer loop iterates over each string `words[i]`.
   - The inner loop iterates over each string `words[j]`.

3. **Avoid Self-Comparison**:
   - We ensure that a string is not compared with itself by checking `i != j`.

4. **Substring Check**:
   - For each pair of strings, we use the `find` method to check if `words[i]` is a substring of `words[j]`.
   - The `find` method returns `std::string::npos` if `words[i]` is not found in `words[j]`.

5. **Store Substrings**:
   - If `words[i]` is found in `words[j]`, we add `words[i]` to the `result` vector.
   - We then break out of the inner loop to avoid adding the same substring multiple times.

6. **Return Result**:
   - Finally, we return the `result` vector containing all the substrings.

### Edge Cases
- **Fewer than Two Strings**: If the input array has fewer than two strings, the function will return an empty vector since no string can be a substring of another.

## Approach 2: Sorting by Length

### Overview
This approach involves sorting the strings by their lengths and then checking for substrings. Sorting helps in reducing the number of comparisons since a shorter string can only be a substring of a longer string.

### Steps

1. **Sort the Strings**:
   - Sort the input array `words` based on the length of the strings in ascending order.

2. **Initialize Result Vector**:
   - Initialize an empty vector `result` to store the substrings.

3. **Single Loop**:
   - Use a single loop to iterate over each string `words[i]`.
   - For each string `words[i]`, check if it is a substring of any string `words[j]` where `j > i`.

4. **Substring Check**:
   - Use the `find` method to check if `words[i]` is a substring of `words[j]`.
   - If `words[i]` is found in `words[j]`, add `words[i]` to the `result` vector and break out of the inner loop.

5. **Return Result**:
   - Finally, return the `result` vector containing all the substrings.