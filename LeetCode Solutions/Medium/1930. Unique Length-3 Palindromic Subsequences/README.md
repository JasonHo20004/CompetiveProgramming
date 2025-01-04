# LeetCode Problem 1930: Unique Length-3 Palindromic Subsequences

## Problem Statement
Given a string `s`, return the number of unique palindromic subsequences of length 3 that are present in `s`.

A **palindromic subsequence** is a sequence that reads the same backward as forward. A subsequence is a sequence derived from another sequence where some elements may be deleted without changing the order of the remaining elements.

## Approach

The solution efficiently counts unique length-3 palindromic subsequences by leveraging the properties of palindromes and the constraints of the problem. Here's a detailed breakdown of the approach:

### Key Observations
1. **Palindrome Structure**: A length-3 palindrome has the form `aba`, where `a` and `b` are characters from the string.
2. **Character Range**: Since the problem specifies that the string consists of lowercase English letters, we can iterate over each character from 'a' to 'z' as the middle character of the palindrome.
3. **Two-Pointer Technique**: For each middle character, we find its first and last occurrence in the string. This helps in identifying the range of characters that can form the palindrome with the current middle character.

### Steps in the Solution
1. **Initialize Count**: Start with a count of 0 to keep track of the number of unique palindromic subsequences.
2. **Iterate Over Middle Characters**: Loop through each character from 'a' to 'z' to consider it as the middle character of the palindrome.
3. **Find First and Last Occurrences**:
   - Use `s.find(middle)` to find the first occurrence of the middle character.
   - Use `s.rfind(middle)` to find the last occurrence of the middle character.
4. **Check Validity**: Ensure that the first occurrence is not the same as the last occurrence and that the first occurrence comes before the last occurrence.
5. **Track Unique Characters**:
   - Use a boolean array `seen` of size 26 (for each letter in the alphabet) to track unique characters between the first and last occurrence of the middle character.
   - Iterate through the substring between the first and last occurrence of the middle character and mark characters as seen.
6. **Count Unique Palindromes**:
   - For each character marked as seen, increment the count as it forms a unique length-3 palindrome with the current middle character.
7. **Return Result**: After processing all possible middle characters, return the total count of unique palindromic subsequences.

### Complexity Analysis
- **Time Complexity**: O(26 * n) = O(n), where `n` is the length of the string. This is because for each of the 26 possible middle characters, we potentially scan the entire string.
- **Space Complexity**: O(1), as the space used (the boolean array `seen`) is constant and does not depend on the input size.

## Example
Consider the string `s = "aabca"`.

- For middle character 'a':
  - First occurrence: index 0
  - Last occurrence: index 4
  - Characters between: 'a', 'b', 'c'
  - Unique palindromes: "aba", "aca"
- For middle character 'b':
  - First occurrence: index 1
  - Last occurrence: index 1
  - No valid range, no palindromes.
- For middle character 'c':
  - First occurrence: index 3
  - Last occurrence: index 3
  - No valid range, no palindromes.

Total unique palindromic subsequences: 2 ("aba", "aca").

## Conclusion
This approach efficiently counts unique length-3 palindromic subsequences by focusing on the middle character and leveraging the properties of palindromes. It ensures that the solution is both time and space efficient, making it suitable for large input sizes.