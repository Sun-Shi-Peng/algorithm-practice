#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    string longestPalindrome(string s) {
        //中心扩展算法
        int begin = 0, len = 0;
        //依次枚举所有中点
        for (int i = 0; i < s.size(); i++)
        {
            //先做一次奇数长度扩展
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--, right++;
            }
            if (right - left - 1 > len)
            {
                begin = left + 1;
                len = right - left - 1;
            }
            //再做一次偶数长度扩展
            left = i, right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--, right++;
            }
            if (right - left - 1 > len)
            {
                begin = left + 1;
                len = right - left - 1;
            }
        }
        return s.substr(begin, len);
    }
};