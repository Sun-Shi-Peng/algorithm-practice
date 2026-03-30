#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char op = '+';
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                // ¼ÆËãÊýÖµ
                long long tmp = 0;
                while (i < s.size() && (s[i] >= '0' && s[i] <= '9'))
                    tmp = tmp * 10 + s[i++] - '0';
                if (op == '+') {
                    st.push(tmp);
                }
                else if (op == '-') {
                    st.push(-tmp);
                }
                else if (op == '*') {
                    tmp = tmp * st.top();
                    st.pop();
                    st.push(tmp);
                }
                else if (op == '/') {
                    tmp = st.top() / tmp;
                    st.pop();
                    st.push(tmp);
                }
            }
            else {
                op = s[i++];
            }
        }

        int ret = 0;
        while (!st.empty()) {
            ret += st.top();
            st.pop();
        }
        return ret;
    }
};