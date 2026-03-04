#define _CRT_SECURE_NO_WARNINGS
class Solution {
    int tmp[50010];
public:
    int reversePairs(vector<int>& record) {
        return MergeSort(record, 0, record.size() - 1);
    }

    int MergeSort(vector<int>& record, int left, int right)
    {
        if (left >= right)
            return 0;

        //1.找中间点，将数组分成两部分
        int mid = left + (right - left) / 2;
        //[left,mid][mid+1,right]

        int ret = 0;
        //2.左边的个数+排序+右边的个数+排序
        ret += MergeSort(record, left, mid);
        ret += MergeSort(record, mid + 1, right);

        //3.一左一右的个数
        int cur1 = left, cur2 = mid + 1, i = 0;
        while (cur1 <= mid && cur2 <= right)
        {
            if (record[cur1] <= record[cur2])
            {
                tmp[i++] = record[cur1++];
            }
            else
            {
                ret += mid - cur1 + 1;
                tmp[i++] = record[cur2++];
            }
        }

        //4.处理一下排序
        while (cur1 <= mid)
            tmp[i++] = record[cur1++];
        while (cur2 <= right)
            tmp[i++] = record[cur2++];
        for (int j = left; j <= right; j++)
            record[j] = tmp[j - left];

        return ret;
    }
};