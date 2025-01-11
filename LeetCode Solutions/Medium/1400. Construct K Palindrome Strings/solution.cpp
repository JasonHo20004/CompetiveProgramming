class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;

        int charCount[26] = {0};

        for (char c : s) {
            charCount[c - 'a']++;
        }

        int oddCount = 0;
        for (int count : charCount) {
            if (count % 2 != 0) {
                oddCount++;
            }
            // Early exit: if oddCount > k, we can return false immediately
            if (oddCount > k) {
                return false;
            }
        }

        // If the number of odd frequencies is less than or equal to k, it's possible
        return true;
    }
};