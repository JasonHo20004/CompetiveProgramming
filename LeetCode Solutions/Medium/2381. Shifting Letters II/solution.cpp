class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shiftDel(n + 1, 0);

        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            shiftDel[start] += (direction == 1 ? 1 : -1);
            shiftDel[end + 1] -= (direction == 1 ? 1 : -1);
        }

        int current = 0;
        for (int i = 0; i < n; ++i) {
            current += shiftDel[i];
            int newChar = ((s[i] - 'a' + current) % 26 + 26) % 26;
            s[i] = 'a' + newChar;
        }
        return s;
    }
};