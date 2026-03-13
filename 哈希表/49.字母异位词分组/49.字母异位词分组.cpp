#define _CRT_SECURE_NO_WARNINGS

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(s);
        }

        vector<vector<string>> vv;
        for (auto [x, y] : hash)
        {
            vv.push_back(y);
        }

        return vv;
    }
};