#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;

        vector<int> hash(26, 0);
        for (auto ch : s1)
            hash[ch - 'a']++;
        for (auto ch : s2)
        {
            hash[ch - 'a']--;
            if (hash[ch - 'a'] < 0)
                return false;
        }
        return true;
    }
};