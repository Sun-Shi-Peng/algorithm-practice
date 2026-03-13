#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //解法二：统一比较
        for (int i = 0; i < strs[0].size(); i++)
        {
            char tmp = strs[0][i];
            for (int j = 0; j < strs.size(); j++)
            {
                if (i == strs[j].size() || strs[j][i] != tmp)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];

        // //解法一：两两比较
        // string common=strs[0];
        // for(int i=1;i<strs.size();i++)
        // {
        //     int size=min(common.size(),strs[i].size());
        //     int count=0;
        //     for(int j=0;j<size;j++)
        //     {
        //         if(common[j]!=strs[i][j])
        //             break;
        //         count++;
        //     }
        //     common=common.substr(0,count);
        // }

        // return common;
    }
};