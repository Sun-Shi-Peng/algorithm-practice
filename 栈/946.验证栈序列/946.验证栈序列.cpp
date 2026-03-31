#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0;
        while (i < pushed.size() && j < popped.size()) {
            st.push(pushed[i++]);
            while (!st.empty() && j < popped.size() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};