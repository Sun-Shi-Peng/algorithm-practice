#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    string decodeString(string s) {
        stack<string> st1;
        stack<int> st2;
        int i = 0;
        string str = "";
        st1.push(str);
        while (i < s.size()) {
            if (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                int tnum = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    tnum = tnum * 10 + s[i++] - '0';
                }
                st2.push(tnum);
            }

            if (i < s.size() && s[i] == '[') {
                i++;
                string tmp = "";
                while (i < s.size() && s[i] >= 'a' && s[i] <= 'z') {
                    tmp += s[i++];
                }
                st1.push(tmp);
            }

            if (i < s.size() && s[i] == ']') {
                i++;
                string tmp1 = st1.top();
                for (int i = 0; i < st2.top() - 1; i++) {
                    st1.top() += tmp1;
                }
                string tmp2 = st1.top();
                st1.pop();
                st2.pop();
                st1.top() += tmp2;
            }

            if (i < s.size() && s[i] >= 'a' && s[i] <= 'z') {
                st1.top() += s[i++];
            }
        }
        return st1.top();
    }
};