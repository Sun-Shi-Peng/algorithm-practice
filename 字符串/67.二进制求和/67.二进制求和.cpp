#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    string addBinary(string a, string b) {
        //¸ß¾«¶È¼Ó·¨
        string ret;
        int m = a.size() - 1;
        int n = b.size() - 1;
        int t = 0;    //¼ÇÂ¼½øÎ»
        while (m >= 0 || n >= 0 || t)
        {
            if (m >= 0)
                t += a[m--] - '0';
            if (n >= 0)
                t += b[n--] - '0';
            ret += t % 2 + '0';
            t /= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};