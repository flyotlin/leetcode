/**
 * Brute force
 * 
 * Time complexity: O(n^3)
 */
class Solution {
private:
    string s;
    bool isPalindrome(int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++, j--;
        }
        return true;
    }

public:
    string longestPalindrome(string ss) {
        s = ss;
        if (s.size() == 1) {
            return s;
        }

        int maxLen = 0;
        int start = 0;
        for (int k = 0; k < s.size(); k++) {
            for (int i = 0, j = k; j < s.size(); i++, j++) {
                if (isPalindrome(i, j)) {
                    if (j-i+1 > maxLen) {
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};