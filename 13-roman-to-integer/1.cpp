class Solution {
public:
    int romanToInt(string s) {
        int res = 0;

        unordered_map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int prev = 0;
        int now = 0;
        for (auto c : s) {
            now = m[c];
            if (prev < now) {
                res = res + now - 2*prev;
            } else {
                res += now;
            }
            prev = now;
        }

        return res;
    }
};