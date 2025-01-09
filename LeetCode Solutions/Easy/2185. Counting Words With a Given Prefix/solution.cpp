class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;

        for (int i = 0; i < words.size(); ++i) {
            bool isPrefix = true;

            if (words[i].size() < pref.size()) {
                continue;
            }

            for (int j = 0; j < pref.size(); ++j) {
                if (words[i][j] != pref[j]) {
                    isPrefix = false;
                    break;
                }
            }

            if (isPrefix) {
                ++count;
            }
        }

        return count;
    }
};
