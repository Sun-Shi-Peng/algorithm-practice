#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int takeAttendance(vector<int>& records) {
        //二分查找
        int n = records.size();
        //第一个值缺失的话直接返回0即可
        if (records[0] != 0)
            return 0;
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            //left指向排序正常的最后一个位置
            if (records[mid] == mid)
                left = mid;
            else
                //right一直在缩小范围
                right = mid - 1;
        }
        //left当前位置是正常的，下一个位置不正常，+1就是缺少的值
        return records[left] + 1;

        //位运算
        // int ret=0;
        // for(auto x:records)
        //     ret^=x;
        // for(int i=0;i<=records.size();i++)
        //     ret^=i;
        // return ret;
    }
};