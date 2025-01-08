# Count Prefix and Suffix Pairs I

## Problem Description

You are given a `0-indexed` string array words.

Let's define a boolean function isPrefixAndSuffix that takes two strings, `str1` and `str2`:

`isPrefixAndSuffix(str1, str2)` returns true if `str1` is both a **prefix** and a **suffix** of `str2`, and false otherwise.


Return an integer denoting the number of index pairs (i, j) such that \(i < j\), and isPrefixAndSuffix(words[i], words[j]) is true.

---

## Approach

### Helper Function: `isPrefixandSuffix`
This function checks if a string `str1` is both a prefix and a suffix of another string `str2`.

- It uses the `substr` method to extract:
  - The beginning of `str2` (prefix).
  - The end of `str2` (suffix).
- Compares the extracted substrings with `str1`.

### Main Function: `countPrefixSuffixPairs`
1. Iterate over all possible pairs `(i, j)` where \( i < j \).
2. For each pair:
   - Use the `isPrefixandSuffix` function to check if `words[i]` is both a prefix and a suffix of `words[j]`.
3. If the condition is satisfied, increment the `count`.

---

## Complexity

### Time Complexity
- **O(n² × m):**
  - \( n \) is the number of words.
  - \( m \) is the average length of the words.
  - For each pair of words, substring operations are performed, which take linear time relative to the length of the words.

### Space Complexity
- **O(1):**
  - Only a constant amount of extra space is used during the computation.

