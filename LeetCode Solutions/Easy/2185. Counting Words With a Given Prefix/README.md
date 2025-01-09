# Prefix Count Problem - Explanation and Approach

## Problem Statement
You are given an array of strings `words` and a string `pref`. Your task is to return the number of strings in `words` that contain `pref` as a prefix.

A **prefix** of a string is any leading contiguous substring of that string.

---

## Approach

The goal is to count how many strings in the `words` array start with the given prefix `pref`. The approach involves iterating through each word in the `words` array and manually checking if the word starts with the given prefix without relying on built-in functions.

---

### Algorithm

1. **Initialize Count:**
   - Start with a variable `count = 0` to keep track of the number of words that match the prefix.

2. **Iterate Through Words:**
   - Use a loop to iterate over each word in the `words` array.

3. **Check Word Length:**
   - If the current word's length is less than the prefix length, it is impossible for the word to contain the prefix. Skip such words.

4. **Compare Characters:**
   - For each character in the prefix, compare it with the corresponding character in the current word.
   - If a mismatch is found, stop checking further characters for this word (early termination).

5. **Count Valid Prefixes:**
   - If all characters of the prefix match with the word's beginning, increment the `count` variable.

6. **Return the Count:**
   - After processing all the words, return the `count` variable as the final result.
