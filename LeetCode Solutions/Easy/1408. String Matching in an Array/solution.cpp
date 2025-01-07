#include <vector>
#include <string>

using namespace std;
//#1 approach:

// class Solution {
// public:
//     vector<string> stringMatching(vector<string>& words) {
//         int n = words.size();
//         vector<string> result;
//         for(int i = 0; i < n; ++i){
//             for(int j = 0; j < n; ++j){
//                 if(i != j && words[j].find(words[i]) != string::npos){
//                     result.push_back(words[i]);
//                     break;
//                 }
//             }
//         }
//         return result;
//     }
// };

//#2 approach:

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // Sort words by length
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        
        vector<string> result;
        int n = words.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        
        return result;
    }
};
