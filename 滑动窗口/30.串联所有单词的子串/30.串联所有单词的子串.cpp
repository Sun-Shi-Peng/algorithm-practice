class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        //统计words中字符出现个数
        unordered_map<string, int> hash1;
        for (auto& w : words)
            hash1[w]++;

        int m = words.size();     //多少个字符串
        int len = words[0].size();  //一个字符串的长度
        for (int i = 0; i < len; i++)    //执行len次
        {
            unordered_map<string, int> hash2;
            for (int left = i, right = i, count = 0; right + len <= s.size(); right += len)
            {
                //进窗口，维护count
                string in = s.substr(right, len);
                hash2[in]++;
                if (hash1.count(in) && hash2[in] <= hash1[in]) count++;

                //出窗口，维护count
                if (right - left + 1 > m * len)  //窗口大小大于字符串长度
                {
                    string out = s.substr(left, len);
                    if (hash1.count(out) && hash2[out] <= hash1[out])
                        count--;
                    hash2[out]--;
                    left += len;
                }

                //更新结果
                if (count == m)
                    ret.emplace_back(left);
            }
        }
        return ret;
    }
};