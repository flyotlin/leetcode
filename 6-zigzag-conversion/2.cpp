class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }

        vector<vector<char>> arr(numRows);

        int direction = 1;
        int row = 0;    // 0 ~ numRows - 1
        for (int i = 0; i < s.size(); i++) {
            if (row == 0) {
                direction = 1;
            } else if (row == numRows - 1) {
                direction = -1;
            }
            arr[row].push_back(s[i]);
            row += direction;
        }

        string res = "";
        for (int i = 0; i < numRows; i++) {
            for (auto c : arr[i]) {
                res += c;
            }
        }
        return res;
    }
};