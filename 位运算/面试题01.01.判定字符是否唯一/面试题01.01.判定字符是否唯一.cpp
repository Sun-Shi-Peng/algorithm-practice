#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    bool isUnique(string astr) {
        //位运算
        if (astr.size() > 26)
            return false;   //鸽巢原理，n个鸽子，n-1个巢，必定有一个鸽子没有巢
        int ret = 0;  //位图，用来记录已经出现过的值
        for (auto ch : astr)
        {
            int m = ch - 'a';   //最右侧为'a'，最左侧为'z'
            if (ret & (1 << m))    // &1 为1说明已经存在过了，直接返回false
                return false;
            ret |= (1 << m);  //到这里说明未存在过，设置为1
        }
        return true;

        // // 使用哈希表
        // unordered_map<char,int> hash(26);
        // //把所有字符装入哈希表
        // for(auto ch:astr)
        // {
        //     hash[ch-'a']++;
        // }
        // //遍历哈希表，如果出现存在但数量不为1的字符则返回false
        // for(int i=0;i<26;i++)
        // {
        //     if(hash[i] >1)
        //         return false;
        // }
        // return true;
    }
};