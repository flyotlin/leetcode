class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, char> m = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for (auto c : s) {
            if (c == ']' || c == ')' || c == '}') {
                if (st.empty()) {
                    return false;
                }

                auto top = st.top();
                if (m[c] == top) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }
};
