class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        bool isNegative = false;
        bool isDigitRead = false;

        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                isDigitRead = true;
                // determine if overflow would happen
                if (res < INT_MIN / 10 || (res == INT_MIN/10 && (c-'0') > 8)) {
                    res = INT_MIN;
                    break;
                }

                if (res > INT_MAX/10 || (res == INT_MAX/10 && (c-'0') > 7)) {
                    res = INT_MAX;
                    break;
                }
                if (isNegative) {
                    res = 10 * res - (c - '0');
                } else {
                    res = 10 * res + (c - '0');
                }
                continue;
            }

            if (isDigitRead) {
                break;
            }
            if (c == ' ') {
                continue;
            }
            if (c == '+') {
                isDigitRead = true;
                continue;
            }
            if (c == '-') {
                isNegative = true;
                isDigitRead = true;
                continue;
            }
            break;
        }
        return res;
    }
};