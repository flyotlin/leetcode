class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows == 1000) {
            return s;
        }

        string res = "";
        int stride = 2 * numRows - 2;
        int n = s.size();
        for (int i = 0; i < numRows; i++) {
            int j = i;
            int count = 0;
            while (j < n) {
                res += s[j];
                if (i == 0 || i == numRows - 1) {
                    j += stride;
                    count += 1;
                } else {
                    // stride - 2i, stride 交錯
                    if (count % 2 == 0) {
                        j += (stride - 2 * i);
                    } else {
                        j += (2 * i);
                    }
                    count += 1;
                }
            }
        }
        return res;
    }
};