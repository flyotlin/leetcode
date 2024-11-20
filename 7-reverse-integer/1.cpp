class Solution {
public:
    int reverse(int x) {
        int res = 0;

        while (x != 0) {
            int remainder = x % 10;

            // 檢查是否 overflow
            if (res > INT_MAX/10 || (res == INT_MAX/10 && remainder > 7)) {
                return 0;
            }
            if (res < INT_MIN/10 || (res == INT_MIN/10 && remainder < -8)) {
                return 0;
            }
            res = 10 * res + remainder;
            x /= 10;
        }
        return res;
    }
};