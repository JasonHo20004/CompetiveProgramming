class Solution {
public:

    // bool isPrefixandSuffix(const string& str1, const string& str2){
    //     return str2.substr(0, str1.length()) == str1 && 
    //        str2.substr(str2.length() - str1.length(), str1.length()) == str1;
    // }

    bool isPrefixandSuffix(const string& str1, const string& str2) {
        if (str1.length() > str2.length()) return false;

        // Check prefix
        for (size_t i = 0; i < str1.length(); ++i) {
            if (str1[i] != str2[i]) return false;
        }

        // Check suffix
        size_t offset = str2.length() - str1.length();
        for (size_t i = 0; i < str1.length(); ++i) {
            if (str1[i] != str2[offset + i]) return false;
        }

        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count =  0;
        for(int i = 0; i < words.size(); ++i){
            for(int j = i + 1;j < words.size(); ++j){
                if(isPrefixandSuffix(words[i], words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};