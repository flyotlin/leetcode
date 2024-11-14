/**
 * Iterative DP (bottom-up)
 * 
 * dp(i, j): if i,j is a palindrome
 */
class Solution {
public:
    bool dp[1002][1002];    // i,j 是否為 palindrome
    string s;
    void solve(int i, int j) {
        // 先更新 dp[i][j]，確認 i,j 是否為 palindrome
        if (i == j) {
            dp[i][j] = true;
            return;
        }
        if (j-i == 1) {
            if (s[i] == s[j]) {
                dp[i][j] = true;
            } else {
                dp[i][j] = false;
            }
            return;
        }

        if (s[i] == s[j] && dp[i+1][j-1]) { // 第二個條件可能會 out-of-bound，所以要多上面的檢查
            dp[i][j] = true;
        } else {
            dp[i][j] = false;
        }
        return;
    }

    string longestPalindrome(string ss) {
        s = ss;

        int start = 0;
        int maxLength = 0;
        memset(dp, false, sizeof(dp));

        for (int g = 0; g < s.size(); g++) {
            for (int i = 0, j = g; j < s.size(); i++, j++) {
                solve(i, j);

                // 再更新最大的 padindrome 長度與起始點
                if (dp[i][j] && j-i+1 > maxLength) {
                    start = i;
                    maxLength = j-i+1;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};