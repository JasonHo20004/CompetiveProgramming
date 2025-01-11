# Problem: Construct K Palindrome Strings

## Description

Given a string `s` and an integer `k`, determine whether it is possible to use all the characters in `s` to construct `k` palindrome strings.

A palindrome string is a string that reads the same forward and backward.

## Example

### Example 1
- **Input:** `s = "annabelle"`, `k = 2`
- **Output:** `true`
- **Explanation:** You can construct two palindromes using all characters: `"anna"` and `"elble"`.

### Example 2
- **Input:** `s = "leetcode"`, `k = 3`
- **Output:** `false`
- **Explanation:** It is not possible to construct 3 palindromes using all characters.

### Example 3
- **Input:** `s = "true"`, `k = 4`
- **Output:** `true`
- **Explanation:** You can construct four palindromes using all characters: `"t"`, `"r"`, `"u"`, `"e"`.

## Approach

To determine if it is possible to construct `k` palindrome strings from the given string `s`, we can use the following approach:

1. **Check Length Constraint:**
   - If the length of the string `s` is less than `k`, it is impossible to construct `k` palindromes, so we return `false`.

2. **Count Character Frequencies:**
   - We count the frequency of each character in the string `s` using an array `charCount` of size 26 (for each letter in the alphabet).

3. **Count Odd Frequencies:**
   - We count how many characters have an odd frequency. This is because a palindrome can have at most one character with an odd frequency (which would be the middle character in the palindrome).

4. **Determine Feasibility:**
   - If the number of characters with odd frequencies is greater than `k`, it is impossible to construct `k` palindromes, so we return `false`.
   - Otherwise, it is possible to construct `k` palindromes, so we return `true`.

## Complexity

- **Time Complexity:** O(n), where n is the length of the string `s`. We iterate through the string once to count character frequencies and once more to count odd frequencies.
- **Space Complexity:** O(1), as we use a fixed-size array to store character frequencies.