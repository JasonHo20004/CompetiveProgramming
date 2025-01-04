int countPalindromicSubsequence(string s) {
    // Total unique palindromes count
    int count = 0;

    // Iterate over each character as the middle character of the palindrome
    for (char middle = 'a'; middle <= 'z'; ++middle) {
        size_t left = s.find(middle);      // First occurrence of middle character
        size_t right = s.rfind(middle);   // Last occurrence of middle character

        if (left != string::npos && right != string::npos && left < right) {
            // Use a boolean array to track unique characters between left and right
            bool seen[26] = {false};

            // Check all characters between left and right
            for (size_t i = left + 1; i < right; ++i) {
                seen[s[i] - 'a'] = true;
            }

            // Count unique palindromes with the current middle character
            for (int i = 0; i < 26; ++i) {
                if (seen[i]) {
                    ++count;
                }
            }
        }
    }

    return count;
}
