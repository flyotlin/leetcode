class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> shown;
        int maxLen = 0;

        int left = 0;
        int right = 0;

        while (right < s.size()) {
            while (shown.count(s[right]) == 1) {
                shown.erase(s[left]);
                left += 1;
            }
            maxLen = max(maxLen, right - left + 1);

            shown.insert(s[right]);
            right += 1;
        }

        return maxLen;
    }
};