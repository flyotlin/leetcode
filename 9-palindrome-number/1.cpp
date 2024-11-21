class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x == 0) {
            return true;
        }

        string s = "";
        while (x > 0) {
            s += ('0' + x % 10);
            x /= 10;
        }

        int left = 0, right = s.size()-1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++, right--;
        }
        return true;
    }
};