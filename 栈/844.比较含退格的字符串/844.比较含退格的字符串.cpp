#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> v1;
        vector<char> v2;
        for (auto& ch : s)
        {
            if (ch == '#')
            {
                if (!v1.empty())
                    v1.pop_back();
            }
            else
            {
                v1.push_back(ch);
            }
        }

        for (auto& ch : t)
        {
            if (ch == '#')
            {
                if (!v2.empty())
                    v2.pop_back();
            }
            else
            {
                v2.push_back(ch);
            }
        }
        return v1 == v2;
    }
};