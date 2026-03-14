#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    string multiply(string n1, string n2) {
        //解法二：先无进位相乘然后想加，最后处理进位
        //1.准备工作
        int m = n1.size(), n = n2.size();
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());
        vector<int> tmp(m + n - 1);

        //2.先无进位相乘然后相加
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                tmp[i + j] += (n1[i] - '0') * (n2[j] - '0');

        //3.处理进位
        string ret;
        int cur = 0, t = 0;
        while (cur < m + n - 1 || t != 0)
        {
            if (cur < m + n - 1)
                t += tmp[cur++];
            ret += t % 10 + '0';
            t /= 10;
        }

        //4.处理前导零(最前面多余的0)
        while (ret.size() > 1 && ret.back() == '0')
        {
            ret.pop_back();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};