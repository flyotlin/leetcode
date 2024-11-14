/**
 * Recursive DP (top-down)
 * 
 * dp(i, j): maximum palindrome length of i,j
 */
class Solution {
public:
    int dp[1002][1002];
    int p[1002][1002];
    string s;
    string ret;
    string longestPalindrome(string ss) {
        s = ss;
        // int dp[1002][1002];
        memset(dp, -1, sizeof(dp));
        memset(p, -1, sizeof(p));

        int a = solve(0, s.size()-1);
        cout << a << endl;

        ret = "";
        getMaxPalindrome(0, s.size()-1);

        return ret;
    }

    int solve(int l, int r) {
        if (l == r) {
            return 1;
        }
        if (l > r) {
            return 0;
        }

        // 有算過就直接 return (memorization)
        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        // 重新計算，並 return value
        if (s[l] == s[r]) {
            dp[l][r] = solve(l+1, r-1) + 2;
            p[l][r] = 0;
        } else if (solve(l, r-1) > solve(l+1, r)) {
            dp[l][r] = solve(l, r-1);
            p[l][r] = 1;
        } else if (solve(l, r-1) <= solve(l+1, r)) {
            dp[l][r] = solve(l+1, r);
            p[l][r] = 2;
        }
        // } else {
        //     dp[l][r] = solve(l+1, r);
        //     p[l][r] = 2;
        // }
        return dp[l][r];
    }

    void getMaxPalindrome(int l, int r) {
        if (l > r) {
            return;
        }
        if (l == r) {
            ret += s[l];
        }

        if (p[l][r] == 0) {
            ret += s[l];
            getMaxPalindrome(l+1, r-1);
            ret += s[r];
        } else if (p[l][r] == 1) {
            getMaxPalindrome(l, r-1);
        } else {
            getMaxPalindrome(l+1, r);
        }
    }

    // bool checkPalindrome(string s, int l, int r) {
    //     while (l <= r) {
    //         if (s[l] != s[r]) {
    //             return false;
    //         }
    //         l++;
    //         r--;
    //     }
    //     return true;
    // }
};